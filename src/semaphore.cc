#include "semaphore.h"

Nan::Persistent<v8::Function> Semaphore::constructor;

NAN_MODULE_INIT(Semaphore::Init) {
	v8::Local<v8::FunctionTemplate> tpl = Nan::New<v8::FunctionTemplate>(New);
	tpl->SetClassName(Nan::New("Semaphore").ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	Nan::SetPrototypeMethod(tpl, "release", Semaphore::Release);

	constructor.Reset(Nan::GetFunction(tpl).ToLocalChecked());
	Nan::Set(target, Nan::New("Semaphore").ToLocalChecked(), Nan::GetFunction(tpl).ToLocalChecked());
}

Semaphore::Semaphore(const char *name, HANDLE semaphore) : name_(name), semaphore_(semaphore) {
}

Semaphore::~Semaphore() {
	if (semaphore_ != NULL) {
		CloseHandle(semaphore_);
	}
}

NAN_METHOD(Semaphore::New) {
	if (info.IsConstructCall()) {
		if (!info[0]->IsString()) {
			return Nan::ThrowError(Nan::Error("Provide a semaphore name"));
		}
		
		const char *name = *Nan::Utf8String(info[0]);
		HANDLE semaphore = CreateSemaphore(
			NULL,
			0,
			1,
			name
		);
		
		if (semaphore == NULL) {
			return Nan::ThrowError(Nan::Error("Error creating semaphore"));
		}
		
		Semaphore *obj = new Semaphore(name, semaphore);
		obj->Wrap(info.This());
		info.GetReturnValue().Set(info.This());
	}
	else {
		const int argc = 1;
		v8::Local<v8::Value> argv[argc] = { info[0] };
		v8::Local<v8::Function> cons = Nan::New(constructor);
		info.GetReturnValue().Set(Nan::NewInstance(cons, argc, argv).ToLocalChecked());
	}
}

NAN_METHOD(Semaphore::Release) {
	Semaphore* obj = Nan::ObjectWrap::Unwrap<Semaphore>(info.This());
	
	if (!obj->semaphore_) {
		info.GetReturnValue().Set(FALSE);
		return;
	}
	
	CloseHandle(obj->semaphore_);
	obj->semaphore_ = NULL;
	info.GetReturnValue().Set(TRUE);
}

#ifndef SEMAPHORE_H
#define SEMAPHORE_H

#include <nan.h>
#include <windows.h>

class Semaphore : public Nan::ObjectWrap {
public:
	static NAN_MODULE_INIT(Init);

private:
	explicit Semaphore(const char *name, HANDLE semaphore);
	~Semaphore();

	static NAN_METHOD(New);
	static NAN_METHOD(Release);
	static Nan::Persistent<v8::Function> constructor;
	
	const char* name_;
	HANDLE semaphore_;
};

#endif // !SEMAPHORE_H

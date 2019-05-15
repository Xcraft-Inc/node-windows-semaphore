#include <nan.h>
#include <windows.h>
#include "semaphore.h"

NAN_MODULE_INIT(Init) {
	Semaphore::Init(target);
}

NODE_MODULE(CreateSemaphore, Init)
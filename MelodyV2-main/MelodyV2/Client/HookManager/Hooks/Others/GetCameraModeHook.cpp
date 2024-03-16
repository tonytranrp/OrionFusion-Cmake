#include "GetCameraModeHook.h"

unsigned int GetCameraModeHook::getCameraPerspectiveMode(__int64 a1) {
	unsigned int result = func(a1);
	mc.cameraPerspectiveMode = result;
	return result;
}
void GetCameraModeHook::init() {
	uintptr_t address = MemoryUtils::getBase() + 0x097C7A0; // This too ez to find so we dont need sig :D
	MemoryUtils::CreateHook("CauseHurtHook", address, (void*)&GetCameraModeHook::getCameraPerspectiveMode, (void*)&func);
}

#include "HIDControllerHook.h"

__int64 HIDControllerHook::HIDController_keyMouse(HIDController* _this, __int64 a2, __int64 a3) {
	mc.setHIDController(_this);
	return func(_this, a2, a3);
}
void HIDControllerHook::init() {
	uintptr_t address = findSig(Sigs::hook::HIDControllerHook);
	MemoryUtils::CreateHook("HIDControllerHook", address, (void*)&HIDControllerHook::HIDController_keyMouse, (void*)&func);
}

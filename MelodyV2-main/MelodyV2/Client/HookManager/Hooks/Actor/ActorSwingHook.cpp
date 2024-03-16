#include "ActorSwingHook.h"

 void ActorSwingHook::Actor_Swing(Actor* _this) {
	func(_this);
}
 void ActorSwingHook::init(uintptr_t address) {
	MemoryUtils::CreateHook("Actor_swingHook", address, (void*)&ActorSwingHook::Actor_Swing, (void*)&func);
}

#include "ActorNormalTickHook.h"
void ActorNormalTickHook::callback(Actor* _this) {
	if (_this == mc.getLocalPlayer()) client->moduleMgr->onNormalTick(_this);
	func(_this);
}
void ActorNormalTickHook::init(uintptr_t address) {
	MemoryUtils::CreateHook("Actor_NormalTickHook", address, (void*)&ActorNormalTickHook::callback, (void*)&func);
}

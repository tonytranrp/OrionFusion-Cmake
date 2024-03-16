#include "ActorShouldRenderHook.h"
bool ActorShouldRenderHook::Actor_ShouldRender(Actor* _this) {
	//return true;
	return func(_this);
}
void ActorShouldRenderHook::init(uintptr_t address) {
	MemoryUtils::CreateHook("Actor_shouldRenderHook", address, (void*)&ActorShouldRenderHook::Actor_ShouldRender, (void*)&func);
}

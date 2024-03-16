#pragma once
#include "../../../../SDK/Classes/Actor.h"
#include "../../../../Utils/MemoryUtils.h"

#include "../../../Client.h"

class ActorIsOnFireHook {
protected:
	using func_t = bool(__fastcall*)(Actor*);
	static inline func_t func;

	static bool Actor_IsOnFire(Actor* _this);
public:
	static void init(uintptr_t address);
};

#pragma once
#include "../../../../SDK/Classes/Actor.h"
#include "../../../../Utils/MemoryUtils.h"

#include "../../../Client.h"

class ActorGetBodyYawHook {
protected:
	using func_t = float(__thiscall*)(Actor*, float);
	static inline func_t func;

	static float Actor_getInterpolatedBodyYaw(Actor* _this, float a1);
public:
	static void init(uintptr_t address);
};
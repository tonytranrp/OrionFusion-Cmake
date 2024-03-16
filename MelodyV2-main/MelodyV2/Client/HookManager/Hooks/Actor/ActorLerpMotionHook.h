#pragma once
#include "../../../../SDK/Classes/Actor.h"
#include "../../../../Utils/MemoryUtils.h"

#include "../../../Client.h"
#include <intrin.h>

class ActorLerpMotionHook {
protected:
	using func_t = bool(__fastcall*)(Actor*, Vec3<float>);
	static inline func_t func;

	static void Actor_LerpMotion(Actor* _this, Vec3<float> a2);

public:
	static void init(uintptr_t address);
};
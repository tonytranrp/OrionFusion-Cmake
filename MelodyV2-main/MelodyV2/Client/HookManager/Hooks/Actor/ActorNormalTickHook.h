#pragma once
#include "../../../../SDK/Classes/Actor.h"
#include "../../../../Utils/MemoryUtils.h"
#include "../../../Client.h"
class ActorNormalTickHook {
protected:
	using func_t = void(__fastcall*)(Actor*);
	static inline func_t func;
	
	static void callback(Actor* _this);
public:
	static void init(uintptr_t address);
};

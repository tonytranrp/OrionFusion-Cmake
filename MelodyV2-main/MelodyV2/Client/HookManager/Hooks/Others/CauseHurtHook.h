#pragma once
#include "../../../../Utils/MemoryUtils.h"
#include "../../../../SDK/Classes/Actor.h"

#include "../../../Client.h"

class CauseHurtHook {
protected:
	using func_t = __int64(__fastcall*)(Actor*, char, unsigned int);
	static inline func_t func;

	static __int64 CauseHurtFunc(Actor* a1, char a2, unsigned int a3);
public:
	static void init();
};

#pragma once
#include "../../../../Utils/MemoryUtils.h"
#include "../../../../SDK/Classes/Actor.h"

#include "../../../Client.h"

class HurtColorHook {
protected:
	using func_t = MC_Color*(__fastcall*)(__int64, MC_Color*, __int64);
	static inline func_t func;

	static MC_Color* HurtColorCallback(__int64 a1, MC_Color* color, __int64 a3);
public:
	static void init();
};

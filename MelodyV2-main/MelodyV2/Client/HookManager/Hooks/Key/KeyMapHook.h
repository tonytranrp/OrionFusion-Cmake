#pragma once
#include "../../../../Utils/MemoryUtils.h"
#include "../../../Client.h"

class KeyMapHook {
protected:
	using func_t = __int64(__fastcall*)(uint64_t, bool);
	static inline func_t func;

	static __int64 KeyPress(uint64_t key, bool isDown);
public:
	static void init();
};

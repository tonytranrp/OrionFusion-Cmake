#pragma once
#include "../../../../Utils/MemoryUtils.h"
#include "../../../../Utils/Math.h"
#include "../../../../SDK/Classes/GameMode.h"

#include "../../../Client.h"

class GameModeGetPickRangeHook {
protected:
	using func_t = float(__fastcall*)(GameMode*, __int64, bool);
	static inline func_t oFunc;

	static float GameMode_getPickRange(GameMode* _this, __int64 inputMode, bool a3);;
public:
	static void init(uintptr_t address);
};
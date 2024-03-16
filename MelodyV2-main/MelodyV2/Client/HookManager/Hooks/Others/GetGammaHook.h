#pragma once
#include "../../../../SDK/Classes/Options.h"
#include "../../../../Utils/MemoryUtils.h"

#include "../../../Client.h"

class GetGammaHook {
protected:
	using func_t = float(__thiscall*)(Options**);
	static inline func_t func;

	static float GetGamma(Options** optionList);
public:
	static void init();
};

#pragma once
#include "../../../../Utils/MemoryUtils.h"
#include "../../../../SDK/Classes/Mob.h"

#include "../../../Client.h"

class GetCurrentSwingDurationHook {
protected:
	using func_t = int(__thiscall*)(Mob* _this);
	static inline func_t func;

	static int Mob_GetCurrentSwingDuration(Mob* _this);
public:
	static void init();
};

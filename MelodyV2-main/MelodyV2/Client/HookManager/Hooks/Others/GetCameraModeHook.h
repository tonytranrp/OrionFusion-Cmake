#pragma once
#include "../../../../Utils/MemoryUtils.h"

#include "../../../Client.h"

class GetCameraModeHook {
protected:
	using func_t = uint32_t(__fastcall*)(__int64);
	static inline func_t func;

	static unsigned int getCameraPerspectiveMode(__int64 a1);
public:
	static void init();
};

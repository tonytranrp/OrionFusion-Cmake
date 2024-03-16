#pragma once
#include "../../../../SDK/Classes/ContainerScreenControllerTickEventContainerScreenControllerTickEvent.h"
#include "../../../../SDK/Classes/Actor.h"
#include "../../../../Utils/MemoryUtils.h"
#include "../../../../SDK/Classes/Options.h"

#include "../../../Client.h"

class onContainerScreenControllerTickEventHook {
protected:
	using func_t = void(__fastcall*)(ContainerScreenControllerTickEvent*);
	static inline func_t oFunc;

	static void onContainerScreenControllerTickEvent_(ContainerScreenControllerTickEvent* event);
public:
	static void init();
};
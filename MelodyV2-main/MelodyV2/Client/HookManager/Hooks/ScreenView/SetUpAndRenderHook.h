#pragma once
#include "../../../../Utils/MemoryUtils.h"
#include "../../../../Utils/RenderUtils.h"
#include "../../../../SDK/Classes/ScreenView.h"
#include "../../../../SDK/Classes/UILayer.h"
#include "../../../../SDK/Classes/MinecraftUIRenderContext.h"
#include "../../../../SDK/GameData.h"

#include "../MinecraftUIRenderContext/DrawImageHook.h"
#include "../MinecraftUIRenderContext/DrawTextHook.h"
#include "../Others/SendPacketHook.h"

#include "../../../Client.h"

class SetUpAndRenderHook {
protected:
	using func_t = __int64(__fastcall*)(ScreenView*, MinecraftUIRenderContext*);
	static inline func_t func;

	static __int64 SetUpAndRender(ScreenView* _this, MinecraftUIRenderContext* renderCtx);
public:
	static void init();
};
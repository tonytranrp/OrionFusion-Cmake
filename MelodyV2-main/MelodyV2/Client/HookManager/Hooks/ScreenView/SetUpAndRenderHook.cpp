#include "SetUpAndRenderHook.h"

__int64 SetUpAndRenderHook::SetUpAndRender(ScreenView* _this, MinecraftUIRenderContext* renderCtx) {
	mc.setClientInstance(renderCtx->clientInstance);
	RenderUtils::SetUp(_this, renderCtx);
	static bool hooked = false;
	if (!hooked) {
		uintptr_t* CtxVTable = *(uintptr_t**)renderCtx;
		uintptr_t* loopbackPacketSenderVTable = *(uintptr_t**)(renderCtx->clientInstance->loopbackPacketSender);
		DrawTextHook::init(CtxVTable[5]);
		DrawImageHook::init(CtxVTable[7]);
		SendPacketHook::init(loopbackPacketSenderVTable[1]);
		hooked = true;
	}
	__int64 result = func(_this, renderCtx);
	if (_this->visualTree->root->GetName() == UILayer::Debug_DebugScreen) {
		client->moduleMgr->onRender(renderCtx);
	}
	return result;
}
void SetUpAndRenderHook::init() {
	uintptr_t address = findSig(Sigs::hook::SetupAndRenderHook);
	MemoryUtils::CreateHook("SetUpAndRenderHook", address, (void*)&SetUpAndRenderHook::SetUpAndRender, (void*)&func);
}
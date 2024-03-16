#include "onContainerScreenControllerTickEventhook.h"
void onContainerScreenControllerTickEventHook::onContainerScreenControllerTickEvent_(ContainerScreenControllerTickEvent* event) {


	client->moduleMgr->onContainerScreenControllerTickEvent(event);
	oFunc(event);
}
void onContainerScreenControllerTickEventHook::init() {
	uintptr_t address = findSig(Sigs::ContainerScreenController::ContainerScreenController_tick);
	MemoryUtils::CreateHook("onContainerScreenControllerTickEventHook", address, (void*)&onContainerScreenControllerTickEventHook::onContainerScreenControllerTickEvent_, (void*)&oFunc);
}
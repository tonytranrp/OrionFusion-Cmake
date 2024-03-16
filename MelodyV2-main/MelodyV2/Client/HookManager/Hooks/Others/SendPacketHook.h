#pragma once
#include "../../../../Utils/MemoryUtils.h"
#include "../../../../SDK/Classes/LoopbackPacketSender.h"

#include "../../../Client.h"

class SendPacketHook {
protected:
	using func_t = void(__fastcall*)(LoopbackPacketSender*, Packet*);
	static inline func_t oFunc;

	static void LoopbackPacketSender_sendToServer(LoopbackPacketSender* _this, Packet* packet);
public:
	static void init(uintptr_t address);
};
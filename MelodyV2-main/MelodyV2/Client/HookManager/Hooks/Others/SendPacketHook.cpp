#include "SendPacketHook.h"
void SendPacketHook::LoopbackPacketSender_sendToServer(LoopbackPacketSender* _this, Packet* packet) {
	if (packet->getName() == "LoginPacket") {
		int numDots = (static_cast<int>(ImGui::GetTime() * 8) % 3) + 1; // Dynamic number of dots
		std::string dots = std::string(numDots, '.');
		Notifications::addNotifBox("Connecting to server" + dots, 5.f);
	} //lol
	LocalPlayer* localPlayer = mc.getLocalPlayer();
	bool shouldCancel = false;
	if (packet->getId() == PacketID::Text) {
		TextPacket* tPacket = (TextPacket*)packet;
		if (tPacket->messageType == 1) {
			client->commandMgr->onSendTextPacket(tPacket, shouldCancel);
		}
	}
	static NoPacket* noPacketMod = (NoPacket*)client->moduleMgr->getModule("NoPacket");

	if (noPacketMod->isEnabled() && localPlayer != nullptr) return;

	client->moduleMgr->onSendPacket(packet, shouldCancel);
	if (shouldCancel) return;
	oFunc(_this, packet);
}
void SendPacketHook::init(uintptr_t address) {
	MemoryUtils::CreateHook("SendPacketHook", address, (void*)&SendPacketHook::LoopbackPacketSender_sendToServer, (void*)&oFunc);
}
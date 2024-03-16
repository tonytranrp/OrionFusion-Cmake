#include "PacketMine.h"
#include "../../../Client.h"

PacketMine::PacketMine() : Module("PacketMine", "NULL", Category::PLAYER) {
	addSlider<float>("Range", "NULL", ValueType::FLOAT_T, &range, 3.f, 10.f);
	addBoolCheck("Silent Switch", "Auto switch to the best pickaxe in hotbar silent", &silenSwitch);
	addBoolCheck("Silent Back", "Switch back to old hotbar after silent switch", &silentBack);
	addEnumSetting("Break Mode", "NULL", { "Auto", "Keybind" }, &breakMode);
	addKeybindSetting("Break keybind", "NULL", &breakKeybind);
}

void PacketMine::setBreakPos(const Vec3<int>& bPos, uint8_t f) {
	GameMode* gm = mc.getGameMode();
	if (gm != nullptr) gm->destroyProgress = 0.f;
	this->breakPos = bPos;
	this->face = f;
}

void PacketMine::Reset() {
	setBreakPos(Vec3<int>(0, 0, 0), -1);
}

std::pair<int, float> PacketMine::getBestPickaxeSlot(Block* block) {
	GameMode* gm = mc.getGameMode();
	PlayerInventory* plrInv = mc.getLocalPlayer()->getPlayerInventory();
	Inventory* inv = plrInv->inventory;

	int oldSlot = plrInv->selectedSlot;
	int bestSlot = plrInv->selectedSlot;
	float destroyRate = gm->getDestroyRate(block);
	for (int i = 0; i < 9; i++) {
		plrInv->selectedSlot = i;
		float value = gm->getDestroyRate(block);
		if (value > destroyRate) {
			destroyRate = value;
			bestSlot = i;
		}
	}
	plrInv->selectedSlot = oldSlot;
	return std::make_pair(bestSlot, destroyRate);
}


void PacketMine::onNormalTick(Actor* actor) {
	LocalPlayer* localPlayer = (LocalPlayer*)actor;
	GameMode* gm = localPlayer->getGameMode();
	if (silenSwitch && shouldSwitchBack && lastSlot != -1) {
		MobEquipmentPacket pk(localPlayer->getRuntimeID(), localPlayer->getPlayerInventory()->inventory->getItemStack(lastSlot), lastSlot, lastSlot);
		mc.getClientInstance()->loopbackPacketSender->sendToServer(&pk);
	}
	shouldSwitchBack = false;
	if (breakPos != Vec3<int>(0, 0, 0)) {
		if (breakPos.dist(*localPlayer->getPosition()) > range) {
			this->Reset();
			return;
		}
		Block* block = localPlayer->dimension->blockSource->getBlock(breakPos);
		if (block == nullptr || block->blockLegacy == nullptr) {
			this->Reset();
			return;
		}
		std::pair<int, float> bestSlot = getBestPickaxeSlot(block);
		if (gm->destroyProgress < 1.f) {
			if (silenSwitch) gm->destroyProgress += bestSlot.second;
			else gm->destroyProgress += gm->getDestroyRate(block);
			if (gm->destroyProgress > 1.f) gm->destroyProgress = 1.f;
		}
		else {
			if (breakMode == 1) {
				if (breakKeybind == 0x0) return;
				if (!mc.isKeyDown(breakKeybind)) return;
			}
			int oldSlot = mc.getLocalPlayer()->getPlayerInventory()->selectedSlot;
			if (silenSwitch) {
				mc.getLocalPlayer()->getPlayerInventory()->selectedSlot = bestSlot.first;
				MobEquipmentPacket pk(localPlayer->getRuntimeID(), localPlayer->getPlayerInventory()->inventory->getItemStack(bestSlot.first), bestSlot.first, bestSlot.first);
				mc.getClientInstance()->loopbackPacketSender->sendToServer(&pk);
			}
			gm->destroyBlock(breakPos, face);
			if (silenSwitch) {
				mc.getLocalPlayer()->getPlayerInventory()->selectedSlot = oldSlot;
				if (silentBack) {
					shouldSwitchBack = true;
					lastSlot = localPlayer->getPlayerInventory()->selectedSlot;
				}
			}
			this->Reset();
		}
	}
}

void PacketMine::onRender(MinecraftUIRenderContext* ctx) {
	GameMode* gm = mc.getGameMode();
	LocalPlayer* localPlayer = mc.getLocalPlayer();
	if (gm == nullptr || localPlayer == nullptr || !mc.getClientInstance()->minecraftGame->canUseKeys) return;

	ImGuiIO& io = ImGui::GetIO();
	static Colors* colorsMod = (Colors*)client->moduleMgr->getModule("Colors");

	float destroyProgress = gm->destroyProgress;
	if (destroyProgress > 1.f) destroyProgress = 1.f;

	UIColor fillColor(255 - int(destroyProgress * 255.f), int(destroyProgress * 255.f), 0, 40);
	UIColor lineColor(255 - int(destroyProgress * 255.f), int(destroyProgress * 255.f), 0, 225);
	if (destroyProgress > 0.f) {
		//AABB aabb = localPlayer->makeAABB(&breakPos);
		//RenderUtils::drawBox(aabb, fillColor, lineColor, 0.3f, true, false);
	}
}

void PacketMine::onImGuiRender(ImDrawList* drawlist) {
}
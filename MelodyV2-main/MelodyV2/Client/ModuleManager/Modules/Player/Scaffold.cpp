#include "Scaffold.h"

Scaffold::Scaffold() : Module("Scaffold", "Op scaffold by toni.", Category::PLAYER) {
    addSlider<int>("Place ticks", "Ticks per blocks place", ValueType::INT_T, &placeticks, 1, 30);
	addBoolCheck("Rotation", "Silent is enough", &rot);
}

bool Scaffold::canPlace(Vec3<float> pos) {
    return mc.getLocalPlayer()->dimension->blockSource->getBlock(pos.floor().toInt())->blockLegacy->blockId == 0;
}

void Scaffold::predictBlock(Vec3<float> pos) {
	GameMode* gm = mc.getGameMode();
	static std::vector<Vec3<float>> blocks;

	if (blocks.empty()) {
		for (int y = -5; y <= 0; y++) {
			for (int x = -5; x <= 5; x++) {
				for (int z = -5; z <= 5; z++) {
					blocks.emplace_back(Vec3<float>(x, y, z));
				}
			}
		}

		std::ranges::sort(blocks, {}, &Math::calculateDistance);
	}

	auto tryPlaceBlock = [&](const Vec3<float>& offset) {
		Vec3<float> currentBlock = (Vec3<float>(pos.floor())).add(offset);
		if (gm->tryPlaceBlock(currentBlock.toInt())) {
			rotAngle = mc.getLocalPlayer()->getPosition()->CalcAngle(currentBlock);
			return true;
		}
		return false;
		};

	for (const Vec3<float>& offset : blocks) {
		if (tryPlaceBlock(offset)) {
			return;
		}
	}
}

void Scaffold::onNormalTick(Actor* actor) {
    LocalPlayer* player = (LocalPlayer*)actor;
    GameMode* gm = mc.getGameMode();
    if (!player || !gm) {
        return;
    }
    if (player->isOnGround() || player->getPosition()->y < targetY + 0.5f || (player->getPosition()->y > targetY))
        targetY = player->getPosition()->floor().y - 0.5f;
    targetBlock = player->getPosition()->floor();
    targetBlock.y = targetY;

    if (canPlace(targetBlock)) {
        for (int i = 0; i < placeticks; i++) {
            predictBlock(targetBlock);
        }
    }
}

void Scaffold::onSendPacket(Packet* packet, bool& shouldCancel) {
	if (rot && packet->getId() == PacketID::PlayerAuthInput) {
		PlayerAuthInputPacket* authPacket = (PlayerAuthInputPacket*)packet;
		authPacket->rotation = rotAngle;
		authPacket->headYaw = rotAngle.y;
	}

	if (rot && packet->getId() == PacketID::MovePlayerPacket) {
		auto* movepacket = (MovePlayerPacket*)packet;
		movepacket->rotation = rotAngle;
		movepacket->headYaw = rotAngle.y;
		movepacket->onGround = true;
		movepacket->tick = 20;
	}
}

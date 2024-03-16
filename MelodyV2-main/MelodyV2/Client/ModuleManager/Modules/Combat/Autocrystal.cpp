#include "AutoCrystal.h"
#include <algorithm>
#include <vector>
#include <ranges>
#include <mutex>
#include <omp.h>
bool Mob = false;
bool placerot = false;
bool breakrot = false;
bool placing = false;
bool breaking = false;
Vec2<float> rotAnglePlace{};
Vec2<float> rotAngleBreak{};
std::mutex breakListMutex;
std::mutex placeListMutex;
int Ticks = 20;
AutoCrystal::AutoCrystal() : Module("AutoCrystal", "NULL", Category::COMBAT, 0x0) {
	addSlider<float>("Target Range", "NULL", ValueType::FLOAT_T, &targetRange, 5.f, 20.f);

	addBoolCheck("Auto Place", "NULL", &autoPlace);
	addSlider<float>("Place Range", "NULL", ValueType::FLOAT_T, &placeRange, 3.f, 10.f);
	addSlider<float>("Max Place Damage", "NULL", ValueType::FLOAT_T, &maxPlaceDame, 1.f, 20.f);
	addSlider<float>("Min Place Damage", "NULL", ValueType::FLOAT_T, &minPlaceDame, 1.f, 20.f);
	addSlider<int>("Multi Place", "NULL", ValueType::INT_T, &multiPlace, 1, 5);
	addSlider<int>("Place Delay", "NULL", ValueType::INT_T, &placeDelay, 0, 20);

	addBoolCheck("Auto Break", "NULL", &autoBreak);
	addSlider<float>("Break Range", "NULL", ValueType::FLOAT_T, &breakRange, 3.f, 10.f);
	addSlider<float>("Max Break Damage", "NULL", ValueType::FLOAT_T, &maxBreakDame, 1.f, 20.f);
	addSlider<float>("Min Break Damage", "NULL", ValueType::FLOAT_T, &minBreakDame, 1.f, 20.f);
	addSlider<int>("Break Delay", "NULL", ValueType::INT_T, &breakDelay, 0, 20);
	addBoolCheck("ID Predict", "NULL", &idPredict);
	
	addSlider<int>("Packets", "NULL", ValueType::INT_T, &packets, 1, 30);
	addSlider<int>("Ticks", "NULL", ValueType::INT_T, &Ticks, 20, 100);
	addSlider<int>("Send Delay", "NULL", ValueType::INT_T, &sendDelay, 0, 20);
	addBoolCheck("Count crystal", "Crystal speed", &Crystalcounter);

	addBoolCheck("Testing", "For testing", &Mob);
}

bool AutoCrystal::sortCrystalByTargetDame(CrystalStruct a1, CrystalStruct a2) {
	return a1.TgDameTake > a2.TgDameTake;
}

bool AutoCrystal::sortEntityByDist(Actor* a1, Actor* a2) {
	auto localPlayerPos = mc.getLocalPlayer()->stateVectorComponent->pos;
	return (a1->stateVectorComponent->pos.dist(localPlayerPos) < a2->stateVectorComponent->pos.dist(localPlayerPos));
}

bool AutoCrystal::isHoldingCrystal() {
	auto* plrInv = mc.getLocalPlayer()->getPlayerInventory();
	auto* inv = plrInv->inventory;
	auto slot = plrInv->selectedSlot;
	auto* itemStack = inv->getItemStack(slot);
	return (itemStack->isValid()) ? itemStack->getItemPtr()->getitemId() == 720 : false;
}

bool AutoCrystal::canPlaceCrystal(Vec3<int> placePos) {
	auto* lp = mc.getLocalPlayer();
	auto* region = lp->dimension->blockSource;
	auto isAir = [](Block* b) { return b && b->blockLegacy->blockName == "air"; };
	auto isObsidianOrBedrock = [](Block* b) { return b && (b->blockLegacy->blockName == "obsidian" || b->blockLegacy->blockName == "bedrock"); };
	if (!(isObsidianOrBedrock(region->getBlock(placePos)) && isAir(region->getBlock(placePos.add(0, 1, 0))) && isAir(region->getBlock(placePos.add(0, 2, 0))))) {// if wanted bedaura need 2 block air so which mean if (air(0,0,0) && the next to it position either it +z or -x or -z or x like 1,0,0)
		return false;
	}
	if (lp->stateVectorComponent->pos.dist(placePos.toFloat().add(0.5f)) > placeRange) return false;
	AABB placeAABB{ placePos.toFloat().add(0.f, 1.f, 0.f), placePos.toFloat().add(1.f, 2.f, 1.f) };
	for (auto* actor : entityList) {
		if (actor->getEntityTypeId() == 71)// <- crystal
			continue;
		AABB targetAABB = *actor->getAABB();
		if (actor->getEntityTypeId() == 319)// <- all ent 
		{
			targetAABB.lower = targetAABB.lower.sub(Vec3<float>(0.1f, 0.f, 0.1f));
			targetAABB.upper = targetAABB.upper.add(0.1f, 0.f, 0.1f);
		}
		if (targetAABB.intersects(placeAABB))
			return false;
	}
	return true;

}
void AutoCrystal::generatePlacement(Actor* target) {
	auto* lp = mc.getLocalPlayer();
	auto* region = lp->dimension->blockSource;

	auto radius = static_cast<int>(7);
	auto targetPos = *target->getPosition();
	auto targetVelocity = target->stateVectorComponent->velocity;

#pragma omp parallel for
	for (auto x = -radius; x <= radius; x++) {// if wanted to make bedaura it only comes to 4 blocks of radius max no -y just +1y i guess
		for (auto y = -7; y <= 7; y++) {
			for (auto z = -radius; z <= radius; z++) {
				Vec3<int> blockPos(static_cast<int>(targetPos.x + targetVelocity.x) + x,
					static_cast<int>(targetPos.y + targetVelocity.y) + y,
					static_cast<int>(targetPos.z + targetVelocity.z) + z);

				// Each thread has its own vector to avoid race conditions
				std::vector<CrystalPlacement> localPlaceList;

				if (canPlaceCrystal(blockPos)) {
					CrystalPlacement placement(blockPos, target);
					if (placement.LpDameTake < maxPlaceDame && placement.TgDameTake >= minPlaceDame) {
						localPlaceList.push_back(placement);
					}
				}

				// Critical section to safely merge local vectors into the global vector
				std::lock_guard<std::mutex> lock(placeListMutex);
				placeList.insert(placeList.end(), localPlaceList.begin(), localPlaceList.end());
			}
		}
	}

	// Sort the global vector after the parallel section
	std::sort(placeList.begin(), placeList.end(), AutoCrystal::sortCrystalByTargetDame);
}
void AutoCrystal::getCrystalActorList(Actor* target) {
	auto* localPlayer = mc.getLocalPlayer();
	std::vector<CrystalBreaker> localBreakList;

	for (auto* ent : entityList) {
		if (ent->getEntityTypeId() != 71 || ent->stateVectorComponent->pos.dist(localPlayer->stateVectorComponent->pos) > breakRange)
			continue;

		CrystalBreaker cBreaker(ent, target);
		if (cBreaker.LpDameTake < maxBreakDame && cBreaker.TgDameTake >= minBreakDame)
			localBreakList.push_back(cBreaker);
	}

	{
		std::lock_guard<std::mutex> lock(breakListMutex);
		breakList.insert(breakList.end(), localBreakList.begin(), localBreakList.end());
		std::sort(breakList.begin(), breakList.end(), AutoCrystal::sortCrystalByTargetDame);
	}
}

void AutoCrystal::placeCrystal() {
	if (placeList.empty() || !isHoldingCrystal())
		return;

	auto* gm = mc.getGameMode();

	if (placeDelayTick >= placeDelay) {
		std::lock_guard<std::mutex> lock(placeListMutex);

		for (CrystalPlacement& placement : placeList) {
			auto rotationToPlacement = mc.getLocalPlayer()->stateVectorComponent->pos.CalcAngle(placement.placePos.toFloat());
			rotAnglePlace = rotationToPlacement;
			placerot = true;
			
			if (!breaking) {
				gm->buildBlock(placement.placePos, Math::random(0, 5), false);
				placing = true;
			}
			placing = false;

			mc.getLocalPlayer()->swing();

			if (multiPlace)
				break;
		}

		placeDelayTick = 0;
	}
	else {
		rotAnglePlace = {};
		placerot = false;
		placeDelayTick++;
	}
}

void AutoCrystal::breakCrystal() {
	if (!autoBreak)
		return;

	auto* gm = mc.getGameMode();

	std::lock_guard<std::mutex> lock(breakListMutex);

	if (!breakList.empty()) {
		highestID = breakList[0].crystalActor->getRuntimeID();

		if (breakDelayTick >= breakDelay) {
			auto rotationToPlacement = mc.getLocalPlayer()->stateVectorComponent->pos.CalcAngle(breakList[0].crystalActor->stateVectorComponent->pos);
			rotAngleBreak = rotationToPlacement;
			breakrot = true;
			
			
			if (!placing) {// if wanted to make a bedaura just replace attack with build block or just do this interact packet code down.
				/*
				* InteractPacket inter(InteractAction::RIGHT_CLICK, mc.getLocalPlayer()->getRuntimeID(), placeList[0].targetActor->stateVectorComponent->pos);
				mc.getClientInstance()->loopbackPacketSender->send(&inter);
				which mean they will right click them and make them EXPLODE in the nether.
				*/
				gm->attack(breakList[0].crystalActor);
				breaking = true;
			}
			breaking = false;
		
			mc.getLocalPlayer()->swing();

			breakDelayTick = 0;
		}
		else {
			rotAngleBreak = {};
			breakrot = false;
			breakDelayTick++;
		}
	}
}

void AutoCrystal::breakIdPredictCrystal() {
	if (!autoBreak || placeList.empty())
		return;

	auto* gm = mc.getGameMode();

	std::lock_guard<std::mutex> lock(breakListMutex);

	if (sendDelayTick >= sendDelay) {
		shouldChangeID = true;

		for (auto i = 0; i < packets; i++) {
			// if wanted to make a bedaura just replace attack with build block or just do this interact packet code down.
				/*
				* InteractPacket inter(InteractAction::RIGHT_CLICK, mc.getLocalPlayer()->getRuntimeID(), placeList[0].targetActor->stateVectorComponent->pos);
				mc.getClientInstance()->loopbackPacketSender->send(&inter);
				which mean they will right click them and make them EXPLODE in the nether.
				*/
			// and and packet attack which are 

			/*
			* ItemUseOnActorInventoryTransaction complxTransac(
					ItemUseOnActorInventoryTransaction::ActionType::Attack,
					breakList[0].crystalActor->getRuntimeID(),
					mc.getLocalPlayer()->getPlayerInventory()->getselectedSlot(),
					mc.getLocalPlayer()->getCarriedItem(),
					mc.getLocalPlayer()->stateVectorComponent->pos
				);

				InventoryTransactionPacket transPkt{ &complxTransac, true };

				mc.getClientInstance()->loopbackPacketSender->send(&transPkt);
			*/// which mean we have a slight advacnedtage but idk how to fix
			InteractPacket inter(InteractAction::LEFT_CLICK, mc.getLocalPlayer()->getRuntimeID(), placeList[0].targetActor->stateVectorComponent->pos.add(0.5f));
			gm->attack(placeList[0].targetActor);
			mc.getClientInstance()->loopbackPacketSender->send(&inter);
			highestID++;
		}

		highestID -= packets;
		shouldChangeID = false;
		sendDelayTick = 0;
	}
	else {
		sendDelayTick++;
	}
}
void AutoCrystal::cleardalist() {
	entityList.clear();
	targetList.clear();
	placeList.clear();
	breakList.clear();
}
void AutoCrystal::onEnable() {
	cleardalist();
	placerot = false;
	breakrot = false;
	placing = false;
	breaking = false;
}

void AutoCrystal::onDisable() {
	cleardalist();
	placerot = false;
	breakrot = false;
	placing = false;
	breaking = false;
}

int getCrystal() {
	auto* plrInv = mc.getLocalPlayer()->getPlayerInventory();
	auto* inv = plrInv->inventory;

	for (auto i = 0; i < 9; i++) {
		auto* itemStack = inv->getItemStack(i);
		
		if (itemStack->isValid() && itemStack->getItemPtr()->gettexture_name() == "end_crystal") {
			return i;
		}
	}
	return plrInv->selectedSlot;
}

void AutoCrystal::onNormalTick(Actor* actor) {
	cleardalist();
	auto* localPlayer = mc.getLocalPlayer();
	auto* level = localPlayer->getLevel();
	if (!level || !localPlayer->dimension->blockSource) return;

	auto* gm = mc.getGameMode();
	auto* plrInv = localPlayer->getPlayerInventory();
	auto* inv = plrInv->inventory;

	for (auto* target : level->getRuntimeActorList()) {
		entityList.push_back(target);
		if (TargetUtils::isTargetValid(target, Mob) &&
			localPlayer->stateVectorComponent->pos.dist(target->stateVectorComponent->pos) < targetRange) {
			targetList.push_back(target);
		}
	}
	
	if (targetList.empty()) return;
	
	std::sort(targetList.begin(), targetList.end(), AutoCrystal::sortEntityByDist);
	if (autoPlace) generatePlacement(targetList[0]);
	if (autoBreak) getCrystalActorList(targetList[0]);

	auto bestSlot = getCrystal();
	auto oldSlot = plrInv->selectedSlot;
	auto shouldSwitch = (bestSlot != plrInv->selectedSlot);
	if (shouldSwitch) {
		plrInv->selectedSlot = bestSlot;
	}
	
	if (isHoldingCrystal()) {
		/*crystalSpeed = MathUtility.clamp(prevCrystalsAmount - InventoryUtility.getItemCount(Items.END_CRYSTAL), 0, 255);
            prevCrystalsAmount = InventoryUtility.getItemCount(Items.END_CRYSTAL);
            invTimer = 0;*/
		crystalSpeed = std::clamp(prevCrystalsAmount - inv->getItemStack(bestSlot)->stackCount, 0, 255);
		prevCrystalsAmount = inv->getItemStack(plrInv->selectedSlot)->stackCount;// <- dont even work
		placeCrystal();
		breakCrystal();
		if (idPredict) breakIdPredictCrystal();
	}
	if (shouldSwitch) plrInv->selectedSlot = oldSlot;
}
void AutoCrystal::onSendPacket(Packet* packet, bool& shouldCancel) {
	if (packet->getId() == PacketID::PlayerAuthInput || packet->getId() == PacketID::MovePlayerPacket) {
		auto* authPacket = static_cast<PlayerAuthInputPacket*>(packet);
		auto* movePacket = static_cast<MovePlayerPacket*>(packet);
		if (placerot) {
			authPacket->ticksAlive = Ticks;
			movePacket->tick = Ticks;
			movePacket->actorRuntimeID = mc.getLocalPlayer()->getRuntimeID();
			authPacket->rotation = rotAnglePlace;
			movePacket->rotation = rotAnglePlace;
			authPacket->headYaw = rotAnglePlace.y;
			movePacket->headYaw = rotAnglePlace.y;
		}
		else if (breakrot) {
			authPacket->ticksAlive = Ticks;
			movePacket->tick = Ticks;
			movePacket->actorRuntimeID = mc.getLocalPlayer()->getRuntimeID();
			authPacket->rotation = rotAngleBreak;
			movePacket->rotation = rotAngleBreak;
			authPacket->headYaw = rotAngleBreak.y;
			movePacket->headYaw = rotAngleBreak.y;
		}

		
	}

	if (!shouldChangeID) return;

	if (packet->getId() == PacketID::InventoryTransaction) {
		auto* invPacket = static_cast<InventoryTransactionPacket*>(packet);
		auto* invComplex = invPacket->transaction.get();

		if (invComplex->type == ComplexInventoryTransaction::Type::ItemUseOnEntityTransaction) {
			*(int*)((uintptr_t)(invComplex)+0x68) = highestID;
		}
	}
	else if (packet->getId() == PacketID::LevelSoundEvent) {
		shouldCancel = true;
	}
}
void AutoCrystal::onRender(MinecraftUIRenderContext* renderCtx) {
	int placed = 0;
	for (CrystalPlacement& placement : placeList) {
		Vec3<float> drawboxCenter = placement.placePos.toFloat().add(0.5f, 1.5f, 0.5f);
		RenderUtils::drawBox(placement.placePos.toFloat(), UIColor(0, 255, 255, 50), UIColor(0, 255, 255, 255), 0.3f, true, false);
		placed++;
		if (placed >= multiPlace) break;
	}
}
void AutoCrystal::onLevelRender() {

}
#pragma once
#include "../../Utils/MemoryUtils.h"

class ComplexInventoryTransaction {
private:
    uintptr_t** VTable;
public:
    enum class Type : int {
        NormalTransaction = 0x0,
        InventoryMismatch = 0x1,
        ItemUseTransaction = 0x2,
        ItemUseOnEntityTransaction = 0x3,
        ItemReleaseTransaction = 0x4,
    };
    Type type; // 0x8
    __int64 data; // 0xC
};
class ItemUseOnActorInventoryTransaction : public ComplexInventoryTransaction {
public:
	enum class ActionType : int32_t {
		Interact = 0,
		Attack = 1,
		ItemInteract = 2,
	};
	ItemUseOnActorInventoryTransaction(ActionType action, int64_t rid, int32_t slot, ItemStack* item, Vec3<float> pos, Vec3<float> clickPos = { 0.f, 0.f, 0.f }) {
		memset(this, 0x0, sizeof(ItemUseOnActorInventoryTransaction));
		using constructor_t = void(__fastcall*)(ItemUseOnActorInventoryTransaction*, ActionType, int64_t, int32_t, ItemStack*, Vec3<float>&, Vec3<float>&);
		static constructor_t  constructor = (constructor_t)(findSig(Sigs::packet::ItemUseOnActorInventoryTransaction));
		constructor(this, action, rid, slot, item, pos, clickPos);
	}
};
//itemuseon entites sigs 48 89 5c 24 ? 57 48 83 ec ? 48 8d 59 ? c7 41 ? ? ? ? ? 48 8d 05 ? ? ? ? 48 89 5c 24 ? 48 89 01 48 8b f9 48 8b cb e8 ? ? ? ? 33 c9 48 8d 05 ? ? ? ? 48 89 4b ? 0f 57 c0 48 89 4b ? 48 89 4b ? 48 8b 5c 24 ? 48 89 07 48 8d 05 ? ? ? ? 48 89 4f ? 89 4f
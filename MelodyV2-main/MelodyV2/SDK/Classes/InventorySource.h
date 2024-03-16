#pragma once
#include <cstdint>

enum class InventorySourceType : int {
    InvalidInventory = -1,
    ContainerInventory = 0,
    GlobalInventory = 1,
    WorldInteraction = 2,
    CreativeInventory = 3,
    NonImplementedFeatureTODO = 99999,
};

enum class InventorySourceFlags : uint32_t {
    NoFlag = 0x0,
    WorldInteraction_Random = 0x1,
};

class InventorySource {
public:
    InventorySourceType inventorySourceType; // 0x0
    int containerID; // 0x4
    InventorySourceFlags inventorySourceFlags; // 0x8
};
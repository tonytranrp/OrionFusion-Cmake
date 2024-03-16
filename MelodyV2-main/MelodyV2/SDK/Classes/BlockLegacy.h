#pragma once
#include <string>
#include "Material.h"
#include "../../Utils/MemoryUtils.h"

class BlockLegacy {
public:
	BUILD_ACCESS(this, std::string, tileName, 0x28);
	BUILD_ACCESS(this, std::string, blockName, 0x50);
	BUILD_ACCESS(this, std::string, blockNamespace, 0x78);
	BUILD_ACCESS(this, Material*, material, 0x128);
	BUILD_ACCESS(this, int, blockId, 0x1A6);
public:
	bool getCollisionShape(AABB* collShapeOut, Block* block, BlockSource* blockSource, const Vec3<int>* pos) {
		return MemoryUtils::CallVFunc<5, bool>(this, collShapeOut, block, blockSource, pos, nullptr);
	}
};
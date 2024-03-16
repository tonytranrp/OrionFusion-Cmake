#pragma once
#include <string>
#include "Material.h"
#include "BlockSource.h" // Ensure that BlockSource.h is included
#include "Block.h"
#include "BlockLegacy.h"
#include "../../Utils/MemoryUtils.h"
#include "../../Utils/Math.h"

class BlockLegacy {
public:
    BUILD_ACCESS(this, std::string, tileName, 0x28);
    BUILD_ACCESS(this, std::string, blockName, 0x50);
    BUILD_ACCESS(this, std::string, blockNamespace, 0x78);
    BUILD_ACCESS(this, Material*, material, 0x128);
    BUILD_ACCESS(this, int, blockId, 0x1A6);

    // Ensure that Block and Vec3 are declared and defined properly
    /*bool getCollisionShape(AABB* coll_shape_out, Block* block, BlockSource* block_source, const Vec3<int>* pos) {
        return MemoryUtils::CallVFunc<5, bool>(this, coll_shape_out, block, block_source, pos, nullptr);
    }*/
};

#include "GameMode.h"
#include "Player.h"
#include "Actor.h"
#include "ActorUniqueID.h"

#include "Block.h"

#include "BlockLegacy.h"

#include "BlockSource.h"

#include "CaretMeasureData.h"

#include "ClientInstance.h"

#include "ComplexInventoryTransaction.h"

#include "Container.h"

#include "ContainerScreenController.h"

#include "ContainerScreenControllerTickEventContainerScreenControllerTickEvent.h"

#include "ContainerScreenControllerEvent.h"

#include "Dimension.h"

#include "FontBitmap.h"

#include "GuiData.h"
#include "HashedString.h"

#include "HIDController.h"
#include "IContainerManager.h"
#include "Inventory.h"
#include "InventoryAction.h"
#include "InventorySource.h"
#include "InventoryTransactionManager.h"
#include "Item.h"
#include "ItemStack.h"
#include "ItemStackBase.h"
#include "Level.h"
#include "LevelRenderer.h"
#include "LevelRendererPlayer.h"
#include "LocalPlayer.h"
#include "LoopbackPacketSender.h"
#include "Material.h"
#include "MaterialPtr.h"
#include "Minecraft.h"
#include "MinecraftGame.h"
#include "MinecraftPacket.h"
#include "MinecraftTimer.h"
#include "MinecraftUIRenderContext.h"
#include "Mob.h"
#include "MobEffectInstance.h"
#include "NetworkItemStackDescriptor.h"
#include "Options.h"
#include "Packet.h"
#include "PathStruct.h"
#include "Player.h"
#include "PlayerInventory.h"
#include "RootUIControl.h"
#include "ScreenContext.h"
#include "ScreenController.h"
#include "ScreenControllerEvent.h"
#include "ScreenView.h"
#include "SimpleContainer.h"
#include "Tessellator.h"
#include "TextHolder.h"
#include "TextMeasureData.h"
#include "TextureData.h"
#include "UILayer.h"
#include "UIProfanityContext.h"
#include "VisualTree.h"
#include "WeakPtr.h"


bool GameMode::tryPlaceBlock(const Vec3<int>& blockPos)
{
	BlockSource* region = player->dimension->blockSource;
	Block* block = region->getBlock(blockPos);
	BlockLegacy* blockLegacy = block->blockLegacy;
	if (!blockLegacy->material->isSolidBlocking())
	{
		Vec3<int> blok(blockPos);

		static std::vector<Vec3<int>> checklist = {
			Vec3<int>(0, -1, 0),
			Vec3<int>(0, 1, 0),
			Vec3<int>(0, 0, -1),
			Vec3<int>(0, 0, 1),
			Vec3<int>(-1, 0, 0),
			Vec3<int>(1, 0, 0)
		};

		int i = 0;

		for (const Vec3<int>& current : checklist)
		{
			Vec3<int> calc = blok.sub(current);
			if (region->getBlock(calc)->blockLegacy->material->isSolidBlocking())
			{
				buildBlock(calc, i, false);
				return true;
			}
			i++;
		}
	}
	return false;
}

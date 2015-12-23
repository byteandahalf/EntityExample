#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <substrate.h>
#include <memory>

#include "mcpe/Item.h"
#include "mcpe/entity/Player.h"
#include "mcpe/level/BlockSource.h"
#include "mcpe/level/Level.h"

#include "EntityExample.h"

bool (*_myUseItemRealPtr)(Item*, ItemInstance*, Player*, int, int, int, signed char, float, float, float);
bool _myUseItemHook(Item* self, ItemInstance* itemStack, Player* player, int x, int y, int z, signed char side, float xx, float yy, float zz) {
	if(self == Item::mStick)
	{
		// spawns our Entity into the world when we tap with a stick
		player->region.getLevel()->addGlobalEntity(std::unique_ptr<Entity>(new EntityExample(player->region, x, y + 2, z)));
	}
	
	return _myUseItemRealPtr(self, itemStack, player, x, y, z, side, xx, yy, zz);
}


JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	MSHookFunction((void*) &Item::useOn, (void*) &_myUseItemHook, (void**) &_myUseItemRealPtr);
	
	return JNI_VERSION_1_2;
}

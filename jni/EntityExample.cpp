#include "EntityExample.h"

EntityExample::EntityExample(BlockSource& region, float x, float y, float z):
	Entity(region) {
	rendererId = 2;  // uses the TNT renderer for now
	setPos({x, y, z});
	_init();
}

EntityType EntityExample::getEntityTypeId() const {
	return EntityType::EXAMPLE;
}

void EntityExample::readAdditionalSaveData(const CompoundTag*) {
	
}

void EntityExample::addAdditionalSaveData(CompoundTag*) {
	
}


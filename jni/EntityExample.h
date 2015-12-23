#pragma once
#include "mcpe/entity/Entity.h"

class EntityExample : public Entity {
	char filler[20]; // this chunk of garbage is only to maintain compatibility with the TNT renderer, and will be removed soon.

public:
	EntityExample(BlockSource&, float, float, float);

	virtual EntityType getEntityTypeId() const;
	virtual void readAdditionalSaveData(const CompoundTag*);
	virtual void addAdditionalSaveData(CompoundTag*);
};


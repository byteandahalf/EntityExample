#pragma once
#include <memory>
struct Entity;

struct Level {
	void addGlobalEntity(std::unique_ptr<Entity>);
};


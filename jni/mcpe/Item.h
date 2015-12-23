#pragma once
struct ItemInstance;
struct Player;

struct Item {
	bool useOn(ItemInstance*, Player*, int, int, int, signed char, float, float, float);

	static Item* mStick; // 280
};


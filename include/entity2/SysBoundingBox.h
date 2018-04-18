#pragma once

#include <SM_Rect.h>

namespace e0 { struct Entity; class World; }

namespace e2
{

class SysBoundingBox
{
public:
	static void Combine(sm::rect& aabb, const e0::World& world, 
		const e0::Entity& entity);

}; // SysBoundingBox

}
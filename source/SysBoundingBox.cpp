#include "entity2/SysBoundingBox.h"
#include "entity2/CompBoundingBox.h"
#include "entity2/CompTransform.h"

#include <entity0/World.h>

namespace e2
{

void SysBoundingBox::Combine(sm::rect& aabb, const e0::World& world,
	                         const e0::Entity& entity)
{
	auto& cbb = world.GetComponent<CompBoundingBox>(entity);
	auto& c_aabb = cbb.rect;
	if (!c_aabb.IsValid()) {
		return;
	}

	auto& cmat = world.GetComponent<CompLocalMat>(entity);
	auto& mat = cmat.mat;
	aabb.Combine(mat * sm::vec2(c_aabb.xmin, c_aabb.ymin));
	aabb.Combine(mat * sm::vec2(c_aabb.xmax, c_aabb.ymin));
	aabb.Combine(mat * sm::vec2(c_aabb.xmax, c_aabb.ymax));
	aabb.Combine(mat * sm::vec2(c_aabb.xmin, c_aabb.ymax));
}

}
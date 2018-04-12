#include "entity2/SysTransform.h"
#include "entity2/CompBoundingBox.h"

#include <SM_Calc.h>

namespace e2
{

void SysTransform::Translate(ecsx::World& world,
	                         const std::vector<ecsx::Entity>& entities,
	                         const sm::vec2& offset)
{
	// pos
	for (auto& entity : entities)
	{
		if (world.HasComponent<CompPosition>(entity)) {
			auto& cpos = world.GetComponent<CompPosition>(entity);
			cpos.pos += offset;
		} else {
			world.AddComponent<CompPosition>(entity, offset);
		}
	}
	// mat
	for (auto& entity : entities)
	{
		auto& cmat = world.GetComponent<CompLocalMat>(entity);
		cmat.mat.Translate(offset.x, offset.y);
	}
	// bb
	for (auto& entity : entities)
	{
		auto& cbb = world.GetComponent<CompBoundingBox>(entity);
		cbb.position += offset;
	}
}

void SysTransform::Rotate(ecsx::World& world, const ecsx::Entity& entity, float rot)
{
	// angle
	if (world.HasComponent<CompAngle>(entity)) {
		auto& cangle = world.GetComponent<CompAngle>(entity);
		cangle.angle += rot;
	} else {
		world.AddComponent<e2::CompAngle>(entity, rot);
	}
	// mat
	auto& cmat = world.GetComponent<CompLocalMat>(entity);
	cmat.mat.Rotate(rot);
	// bb
	auto& cbb = world.GetComponent<CompBoundingBox>(entity);
	cbb.angle += rot;
}

void SysTransform::SetOffset(ecsx::World& world, 
	                         const ecsx::Entity& entity, 
	                         const sm::vec2& offset)
{
	if (world.HasComponent<CompOffset>(entity)) {
		auto& coffset = world.GetComponent<CompOffset>(entity);
		coffset.offset = offset;
	} else {
		world.AddComponent<CompOffset>(entity, offset);
	}
}

sm::vec2 SysTransform::CalcCenter(const ecsx::World& world, 
	                              const ecsx::Entity& entity)
{
	sm::vec2 pos;
	if (world.HasComponent<CompPosition>(entity)) {
		pos = world.GetComponent<CompPosition>(entity).pos;
	}
	sm::vec2 offset;
	if (world.HasComponent<CompOffset>(entity)) {
		offset = world.GetComponent<CompOffset>(entity).offset;
	}
	float angle = 0;
	if (world.HasComponent<CompAngle>(entity)) {
		angle = world.GetComponent<CompAngle>(entity).angle;
	}
	return pos + sm::rotate_vector(-offset, angle) + offset;
}

void SysTransform::UpdateLocalMat(const ecsx::World& world,
	                            const ecsx::Entity& entity)
{
	sm::vec2 center = CalcCenter(world, entity);
	float angle = 0;
	if (world.HasComponent<CompAngle>(entity)) {
		angle = world.GetComponent<CompAngle>(entity).angle;
	}
	sm::vec2 scale;
	if (world.HasComponent<CompScale>(entity)) {
		scale = world.GetComponent<CompScale>(entity).scale;
	}
	sm::vec2 shear;
	if (world.HasComponent<CompShear>(entity)) {
		shear = world.GetComponent<CompShear>(entity).shear;
	}

	auto& cmat = world.GetComponent<CompLocalMat>(entity);
	cmat.mat.SetTransformation(center.x, center.y, angle, scale.x,
		scale.y, 0, 0, shear.x, shear.y);
}

}
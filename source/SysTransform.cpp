#include "entity2/SysTransform.h"
#include "entity2/CompBoundingBox.h"

#include <SM_Calc.h>

namespace e2
{

void SysTransform::Translate(e0::World& world,
	                         const std::vector<e0::Entity>& entities,
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
	// update
	for (auto& entity : entities) {
		UpdateLocalMat(world, entity);
	}
}

void SysTransform::Translate(e0::World& world, const e0::Entity& entity, const sm::vec2& offset)
{
	// pos
	if (world.HasComponent<CompPosition>(entity)) {
		auto& cpos = world.GetComponent<CompPosition>(entity);
		cpos.pos += offset;
	} else {
		world.AddComponent<CompPosition>(entity, offset);
	}
	// mat
	auto& cmat = world.GetComponent<CompLocalMat>(entity);
	cmat.mat.Translate(offset.x, offset.y);
	// bb
	auto& cbb = world.GetComponent<CompBoundingBox>(entity);
	cbb.position += offset;
	// update
	UpdateLocalMat(world, entity);
}

void SysTransform::Rotate(e0::World& world, const e0::Entity& entity, float rot)
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
	// update
	UpdateLocalMat(world, entity);
}

void SysTransform::SetPosition(e0::World& world,
	                           const e0::Entity& entity,
	                           const sm::vec2& pos)
{
	if (world.HasComponent<CompPosition>(entity)) {
		auto& cpos = world.GetComponent<CompPosition>(entity);
		cpos.pos = pos;
	} else {
		world.AddComponent<CompPosition>(entity, pos);
	}
	// update
	UpdateLocalMat(world, entity);
}

void SysTransform::SetAngle(e0::World& world,
	                        const e0::Entity& entity,
	                        float angle)
{
	if (world.HasComponent<CompAngle>(entity)) {
		auto& cangle = world.GetComponent<CompAngle>(entity);
		cangle.angle = angle;
	} else {
		world.AddComponent<CompAngle>(entity, angle);
	}
	// update
	UpdateLocalMat(world, entity);
}

void SysTransform::SetScale(e0::World& world,
	                        const e0::Entity& entity,
	                        const sm::vec2& scale)
{
	if (world.HasComponent<CompScale>(entity)) {
		auto& coffset = world.GetComponent<CompScale>(entity);
		coffset.scale = scale;
	} else {
		world.AddComponent<CompScale>(entity, scale);
	}
	// update
	UpdateLocalMat(world, entity);
}

void SysTransform::SetShear(e0::World& world,
	                        const e0::Entity& entity,
	                        const sm::vec2& shear)
{
	if (world.HasComponent<CompShear>(entity)) {
		auto& cshear = world.GetComponent<CompShear>(entity);
		cshear.shear = shear;
	} else {
		world.AddComponent<CompShear>(entity, shear);
	}
	// update
	UpdateLocalMat(world, entity);
}

void SysTransform::SetOffset(e0::World& world,
	                         const e0::Entity& entity,
	                         const sm::vec2& offset)
{
	if (world.HasComponent<CompOffset>(entity)) {
		auto& coffset = world.GetComponent<CompOffset>(entity);
		coffset.offset = offset;
	} else {
		world.AddComponent<CompOffset>(entity, offset);
	}
	// update
	UpdateLocalMat(world, entity);
}

sm::vec2 SysTransform::CalcCenter(const e0::World& world,
	                              const e0::Entity& entity)
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

void SysTransform::UpdateLocalMat(const e0::World& world,
	                              const e0::Entity& entity)
{
	sm::vec2 center = CalcCenter(world, entity);
	float angle = 0;
	if (world.HasComponent<CompAngle>(entity)) {
		angle = world.GetComponent<CompAngle>(entity).angle;
	}
	sm::vec2 scale(1, 1);
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
#pragma once

#include "entity2/CompTransform.h"

#include <entity0/World.h>

namespace e2
{

inline
sm::vec2 SysTransform::GetPosition(const e0::World& world, const e0::Entity& entity)
{
	return world.HasComponent<CompPosition>(entity) ?
		world.GetComponent<CompPosition>(entity).pos : sm::vec2(0, 0);
}

inline
float SysTransform::GetAngle(const e0::World& world, const e0::Entity& entity)
{
	return world.HasComponent<CompAngle>(entity) ?
		world.GetComponent<CompAngle>(entity).angle : 0;
}

inline
sm::vec2 SysTransform::GetScale(const e0::World& world, const e0::Entity& entity)
{
	return world.HasComponent<CompScale>(entity) ?
		world.GetComponent<CompScale>(entity).scale : sm::vec2(1, 1);
}

inline
sm::vec2 SysTransform::GetShear(const e0::World& world, const e0::Entity& entity)
{
	return world.HasComponent<CompShear>(entity) ?
		world.GetComponent<CompShear>(entity).shear : sm::vec2(0, 0);
}

inline
sm::vec2 SysTransform::GetOffset(const e0::World& world, const e0::Entity& entity)
{
	return world.HasComponent<CompOffset>(entity) ?
		world.GetComponent<CompOffset>(entity).offset : sm::vec2(0, 0);
}

}
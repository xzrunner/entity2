#pragma once

#include "entity2/CompTransform.h"

#include <ecsx/World.h>

namespace e2
{

inline
sm::vec2 SysTransform::GetPosition(const ecsx::World& world, const ecsx::Entity& entity)
{
	return world.HasComponent<CompPosition>(entity) ?
		world.GetComponent<CompPosition>(entity).pos : sm::vec2(0, 0);
}

inline
float SysTransform::GetAngle(const ecsx::World& world, const ecsx::Entity& entity)
{
	return world.HasComponent<CompAngle>(entity) ?
		world.GetComponent<CompAngle>(entity).angle : 0;
}

inline
sm::vec2 SysTransform::GetScale(const ecsx::World& world, const ecsx::Entity& entity)
{
	return world.HasComponent<CompScale>(entity) ?
		world.GetComponent<CompScale>(entity).scale : sm::vec2(1, 1);
}

inline
sm::vec2 SysTransform::GetShear(const ecsx::World& world, const ecsx::Entity& entity)
{
	return world.HasComponent<CompShear>(entity) ?
		world.GetComponent<CompShear>(entity).shear : sm::vec2(0, 0);
}

inline
sm::vec2 SysTransform::GetOffset(const ecsx::World& world, const ecsx::Entity& entity)
{
	return world.HasComponent<CompOffset>(entity) ?
		world.GetComponent<CompOffset>(entity).offset : sm::vec2(0, 0);
}

}
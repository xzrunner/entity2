#pragma once

#include <SM_Vector.h>

#include <vector>

namespace ecsx { class World; struct Entity; }

namespace e2
{

class SysTransform
{
public:
	static void Translate(ecsx::World& world, 
		const std::vector<ecsx::Entity>& entities,
		const sm::vec2& offset);

	static void Rotate(ecsx::World& world, const ecsx::Entity& entity,
		float rot);

	static void SetOffset(ecsx::World& world, const ecsx::Entity& entity,
		const sm::vec2& offset);

	static sm::vec2 GetPosition(const ecsx::World& world, const ecsx::Entity& entity);
	static float    GetAngle(const ecsx::World& world, const ecsx::Entity& entity);
	static sm::vec2 GetScale(const ecsx::World& world, const ecsx::Entity& entity);
	static sm::vec2 GetShear(const ecsx::World& world, const ecsx::Entity& entity);
	static sm::vec2 GetOffset(const ecsx::World& world, const ecsx::Entity& entity);

	static sm::vec2 CalcCenter(const ecsx::World& world, 
		const ecsx::Entity& entity);

private:
	static void UpdateLocalMat(const ecsx::World& world,
		const ecsx::Entity& entity);

}; // SysTransform

}

#include "entity2/SysTransform.inl"
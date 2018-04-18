#pragma once

#include <SM_Vector.h>

#include <vector>

namespace e0 { class World; struct Entity; }

namespace e2
{

class SysTransform
{
public:
	static void Translate(e0::World& world, 
		const std::vector<e0::Entity>& entities,
		const sm::vec2& offset);

	static void Translate(e0::World& world, const e0::Entity& entity, const sm::vec2& offset);
	static void Rotate(e0::World& world, const e0::Entity& entity, float rot);

	static void SetPosition(e0::World& world, const e0::Entity& entity, const sm::vec2& pos);
	static void SetAngle(e0::World& world, const e0::Entity& entity, float angle);
	static void SetScale(e0::World& world, const e0::Entity& entity, const sm::vec2& scale);
	static void SetShear(e0::World& world, const e0::Entity& entity, const sm::vec2& shear);
	static void SetOffset(e0::World& world, const e0::Entity& entity, const sm::vec2& offset);

	static sm::vec2 GetPosition(const e0::World& world, const e0::Entity& entity);
	static float    GetAngle(const e0::World& world, const e0::Entity& entity);
	static sm::vec2 GetScale(const e0::World& world, const e0::Entity& entity);
	static sm::vec2 GetShear(const e0::World& world, const e0::Entity& entity);
	static sm::vec2 GetOffset(const e0::World& world, const e0::Entity& entity);

	static sm::vec2 CalcCenter(const e0::World& world, const e0::Entity& entity);

private:
	static void UpdateLocalMat(const e0::World& world, const e0::Entity& entity);

}; // SysTransform

}

#include "entity2/SysTransform.inl"

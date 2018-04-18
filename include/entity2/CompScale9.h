#pragma once

#include <entity0/Component.h>
#include <entity0/Entity.h>
#include <SM_Vector.h>

namespace e0 { class World; }

namespace e2
{

struct CompScale9 : public e0::Component
{
	enum Scale9Type
	{
		S9_NULL = 0,
		S9_9GRID,
		S9_3GRID_HORI,
		S9_3GRID_VERT,
		S9_6GRID_UPPER,
		S9_9GRID_HOLLOW
	};

	enum Scale9Idx
	{
		S9_DOWN_LEFT = 0,
		S9_DOWN_CENTER = 1,
		S9_DOWN_RIGHT = 2,

		S9_MID_LEFT = 3,
		S9_MID_CENTER = 4,
		S9_MID_RIGHT = 5,

		S9_TOP_LEFT = 6,
		S9_TOP_CENTER = 7,
		S9_TOP_RIGHT = 8,
	};

	Scale9Type type;

	float width, height;

	// 6 7 8
	// 3 4 5
	// 0 1 2
	e0::Entity grids[9];

	int sz_left, sz_right, sz_top, sz_down;

public:
	void SetWidth(e0::World& world, float width);
	void SetHeight(e0::World& world, float height);
	void SetSize(e0::World& world, float width, float height);

private:
	void ResizeNode(e0::World& world, Scale9Idx idx, const sm::vec2& center,
		float dst_w, float dst_h, bool no_scale_w, bool no_scale_h);

	sm::vec2 GetChildSize(const e0::World& world, Scale9Idx idx) const;

	float GetLeftWidth(const e0::World& world) const;
	float GetRightWidth(const e0::World& world) const;
	float GetDownHeight(const e0::World& world) const;
	float GetTopHeight(const e0::World& world) const;

}; // CompScale9

}
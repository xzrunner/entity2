#pragma once

#include <cu/cu_stl.h>
#include <entity0/Component.h>
#include <SM_Rect.h>
#include <SM_Vector.h>

namespace e2
{

struct CompBoundingBox : public e0::Component
{
	CompBoundingBox() : angle(0) {}
	CompBoundingBox(const sm::rect& rect) : angle(0), rect(rect) {}

	void GetBoundPos(CU_VEC<sm::vec2>& bound) const;

	bool IsContain(const sm::vec2& pos) const;
	bool IsContain(const sm::rect& rect) const;
	bool IsIntersect(const sm::rect& rect) const;

	sm::rect rect;
	sm::vec2 position;
	float    angle;

}; // CompBoundingBox

}
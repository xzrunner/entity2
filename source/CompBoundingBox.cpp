#include "entity2/CompBoundingBox.h"

#include <SM_Calc.h>

namespace e2
{

void CompBoundingBox::GetBoundPos(CU_VEC<sm::vec2>& bound) const
{
	bound.resize(4);
	bound[0] = sm::rotate_vector(sm::vec2(rect.xmin, rect.ymin), angle) + position;
	bound[1] = sm::rotate_vector(sm::vec2(rect.xmax, rect.ymin), angle) + position;
	bound[2] = sm::rotate_vector(sm::vec2(rect.xmax, rect.ymax), angle) + position;
	bound[3] = sm::rotate_vector(sm::vec2(rect.xmin, rect.ymax), angle) + position;
}

bool CompBoundingBox::IsContain(const sm::vec2& pos) const
{
	sm::vec2 position = sm::rotate_vector(pos - position, -angle);
	return sm::is_point_in_rect(position, rect);
}

bool CompBoundingBox::IsContain(const sm::rect& rect) const
{
	return IsContain(sm::vec2(rect.xmin, rect.ymin))
		&& IsContain(sm::vec2(rect.xmax, rect.ymin))
		&& IsContain(sm::vec2(rect.xmax, rect.ymax))
		&& IsContain(sm::vec2(rect.xmin, rect.ymax));
}

bool CompBoundingBox::IsIntersect(const sm::rect& rect) const
{
	CU_VEC<sm::vec2> convex0, convex1;
	convex0.resize(4);
	convex1.resize(4);
	convex0[0] = sm::rotate_vector(sm::vec2(rect.xmin, rect.ymin), angle) + position;
	convex0[1] = sm::rotate_vector(sm::vec2(rect.xmax, rect.ymin), angle) + position;
	convex0[2] = sm::rotate_vector(sm::vec2(rect.xmax, rect.ymax), angle) + position;
	convex0[3] = sm::rotate_vector(sm::vec2(rect.xmin, rect.ymax), angle) + position;
	convex1[0] = sm::vec2(rect.xmin, rect.ymin);
	convex1[1] = sm::vec2(rect.xmax, rect.ymin);
	convex1[2] = sm::vec2(rect.xmax, rect.ymax);
	convex1[3] = sm::vec2(rect.xmin, rect.ymax);
	return is_convex_intersect_convex(convex0, convex1);
}

}
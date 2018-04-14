#include "entity2/CompScale9.h"
#include "entity2/SysTransform.h"
#include "entity2/CompBoundingBox.h"

#include <sm_const.h>
#include <SM_Calc.h>

namespace e2
{

void CompScale9::SetWidth(ecsx::World& world, float _width)
{
	if (width != _width) {
		SetSize(world, _width, height);
	}
}

void CompScale9::SetHeight(ecsx::World& world, float _height)
{
	if (height != _height) {
		SetSize(world, width, _height);
	}
}

void CompScale9::SetSize(ecsx::World& world, float width, float height)
{
	if (width == width && height == height) {
		return;
	}

	width  = width;
	height = height;

	switch (type)
	{
	case S9_9GRID:
		{
			float w0 = GetLeftWidth(world),
				  w2 = GetRightWidth(world),
				  w1 = width - w0 - w2;
			float h0 = GetDownHeight(world),
				  h2 = GetTopHeight(world),
				  h1 = height - h0 - h2;

			ResizeNode(world, S9_DOWN_LEFT, sm::vec2(-w0*0.5f-w1*0.5f, -h0*0.5f-h1*0.5f), w0, h0, true, true);
			ResizeNode(world, S9_DOWN_CENTER, sm::vec2(0.0f, -h0*0.5f-h1*0.5f), w1, h0, false, true);
			ResizeNode(world, S9_DOWN_RIGHT, sm::vec2(w1*0.5f+w2*0.5f, -h0*0.5f-h1*0.5f), w2, h0, true, true);

			ResizeNode(world, S9_MID_LEFT, sm::vec2(-w0*0.5f-w1*0.5f, 0.0f), w0, h1, true, false);
			ResizeNode(world, S9_MID_CENTER, sm::vec2(0.0f, 0.0f), w1, h1, false, false);
			ResizeNode(world, S9_MID_RIGHT, sm::vec2(w1*0.5f+w2*0.5f, 0.0f), w2, h1, true, false);

			ResizeNode(world, S9_TOP_LEFT, sm::vec2(-w0*0.5f-w1*0.5f, h1*0.5f+h2*0.5f), w0, h2, true, true);
			ResizeNode(world, S9_TOP_CENTER, sm::vec2(0.0f, h1*0.5f+h2*0.5f), w1, h2, false, true);
			ResizeNode(world, S9_TOP_RIGHT, sm::vec2(w1*0.5f+w2*0.5f, h1*0.5f+h2*0.5f), w2, h2, true, true);
		}
		break;
	case S9_9GRID_HOLLOW:
		{
			float w0 = GetLeftWidth(world),
				  w2 = GetRightWidth(world),
				  w1 = width - w0 - w2;
			float h0 = GetDownHeight(world),
				  h2 = GetTopHeight(world),
				  h1 = height - h0 - h2;

			ResizeNode(world, S9_DOWN_LEFT, sm::vec2(-w0*0.5f-w1*0.5f, -h0*0.5f-h1*0.5f), w0, h0, true, true);
			ResizeNode(world, S9_DOWN_CENTER, sm::vec2(0.0f, -h0*0.5f-h1*0.5f), w1, h0, false, true);
			ResizeNode(world, S9_DOWN_RIGHT, sm::vec2(w1*0.5f+w2*0.5f, -h0*0.5f-h1*0.5f), w2, h0, true, true);

			ResizeNode(world, S9_MID_LEFT, sm::vec2(-w0*0.5f-w1*0.5f, 0.0f), w0, h1, true, false);
			ResizeNode(world, S9_MID_RIGHT, sm::vec2(w1*0.5f+w2*0.5f, 0.0f), w2, h1, true, false);

			ResizeNode(world, S9_TOP_LEFT, sm::vec2(-w0*0.5f-w1*0.5f, h1*0.5f+h2*0.5f), w0, h2, true, true);
			ResizeNode(world, S9_TOP_CENTER, sm::vec2(0.0f, h1*0.5f+h2*0.5f), w1, h2, false, true);
			ResizeNode(world, S9_TOP_RIGHT, sm::vec2(w1*0.5f+w2*0.5f, h1*0.5f+h2*0.5f), w2, h2, true, true);
		}
		break;
	case S9_6GRID_UPPER:
		{
			float w0 = GetLeftWidth(world),
				  w2 = GetRightWidth(world),
				  w1 = width - w0 - w2;
			float h2 = GetTopHeight(world),
				  h1 = height - h2;

			ResizeNode(world, S9_MID_LEFT, sm::vec2(-w0*0.5f-w1*0.5f, 0.0f), w0, h1, true, false);
			ResizeNode(world, S9_MID_CENTER, sm::vec2(0.0f, 0.0f), w1, h1, false, false);
			ResizeNode(world, S9_MID_RIGHT, sm::vec2(w1*0.5f+w2*0.5f, 0.0f), w2, h1, true, false);

			ResizeNode(world, S9_TOP_LEFT, sm::vec2(-w0*0.5f-w1*0.5f, h1*0.5f+h2*0.5f), w0, h2, true, true);
			ResizeNode(world, S9_TOP_CENTER, sm::vec2(0.0f, h1*0.5f+h2*0.5f), w1, h2, false, true);
			ResizeNode(world, S9_TOP_RIGHT, sm::vec2(w1*0.5f+w2*0.5f, h1*0.5f+h2*0.5f), w2, h2, true, true);
		}
		break;
	case S9_3GRID_HORI:
		{
			float w0 = GetLeftWidth(world),
				  w2 = GetRightWidth(world),
				  w1 = width - w0 - w2; 

			ResizeNode(world, S9_MID_LEFT, sm::vec2(-w0*0.5f-w1*0.5f, 0.0f), w0, height, true, true);
			ResizeNode(world, S9_MID_CENTER, sm::vec2(0.0f, 0.0f), w1, height, false, true);
			ResizeNode(world, S9_MID_RIGHT, sm::vec2(w1*0.5f+w2*0.5f, 0.0f), w2, height, true, true);
		}
		break;
	case S9_3GRID_VERT:
		{
			float h0 = GetDownHeight(world),
				  h2 = GetTopHeight(world),
				  h1 = height - h0 - h2;

			ResizeNode(world, S9_DOWN_CENTER, sm::vec2(0.0f, -h0*0.5f-h1*0.5f), width, h0, true, true);
			ResizeNode(world, S9_MID_CENTER, sm::vec2(0.0f, 0.0f), width, h1, true, false);
			ResizeNode(world, S9_TOP_CENTER, sm::vec2(0.0f, h1*0.5f+h2*0.5f), width, h2, true, true);
		}
		break;
	default:
		break;
	}
}

void CompScale9::ResizeNode(ecsx::World& world, Scale9Idx idx, const sm::vec2& center, float dst_w,
	                        float dst_h, bool no_scale_w, bool no_scale_h)
{
	if (idx < 0 || idx >= 9 || grids[idx].IsNull()) {
		return;
	}

	auto& grid = grids[idx];

	if (dst_w < 0) { dst_w = 1; }
	if (dst_h < 0) { dst_h = 1; }

	SysTransform::SetPosition(world, grid, center);

	float src_w, src_h;
	auto& cbb = world.GetComponent<CompBoundingBox>(grid);
	src_w = cbb.rect.Width();
	src_h = cbb.rect.Height();
	if (src_w == 0 || src_h == 0) {
		return;
	}

	float angle = SysTransform::GetAngle(world, grid);
	const float times = angle / SM_PI;
	bool rotate = fabs(times - (int)times) > 0.1f;
	if (sz_left != 0 && sz_right != 0 && sz_top != 0 && sz_down != 0)
	{
		if (rotate)
		{
			switch (idx)
			{
			case S9_DOWN_LEFT:
				src_h = static_cast<float>(sz_left);
				src_w = static_cast<float>(sz_down);
				break;
			case S9_DOWN_CENTER:
				src_w = static_cast<float>(sz_down);
				break;
			case S9_DOWN_RIGHT:
				src_h = static_cast<float>(sz_right);
				src_w = static_cast<float>(sz_down);
				break;
			case S9_MID_LEFT:
				src_h = static_cast<float>(sz_left);
				break;
			case S9_MID_RIGHT:
				src_h = static_cast<float>(sz_right);
				break;
			case S9_TOP_LEFT:
				src_h = static_cast<float>(sz_left);
				src_w = static_cast<float>(sz_top);
				break;
			case S9_TOP_CENTER:
				src_w = static_cast<float>(sz_top);
				break;
			case S9_TOP_RIGHT:
				src_h = static_cast<float>(sz_right);
				src_w = static_cast<float>(sz_top);
				break;
			default:
				break;
			}
		}
		else
		{
			switch (idx)
			{
			case S9_DOWN_LEFT:
				src_w = static_cast<float>(sz_left);
				src_h = static_cast<float>(sz_down);
				break;
			case S9_DOWN_CENTER:
				src_h = static_cast<float>(sz_down);
				break;
			case S9_DOWN_RIGHT:
				src_w = static_cast<float>(sz_right);
				src_h = static_cast<float>(sz_down);
				break;
			case S9_MID_LEFT:
				src_w = static_cast<float>(sz_left);
				break;
			case S9_MID_RIGHT:
				src_w = static_cast<float>(sz_right);
				break;
			case S9_TOP_LEFT:
				src_w = static_cast<float>(sz_left);
				src_h = static_cast<float>(sz_top);
				break;
			case S9_TOP_CENTER:
				src_h = static_cast<float>(sz_top);
				break;
			case S9_TOP_RIGHT:
				src_w = static_cast<float>(sz_right);
				src_h = static_cast<float>(sz_top);
				break;
			default:
				break;
			}
		}
	}

	auto old_scale = SysTransform::GetScale(world, grid);
	sm::vec2 new_scale;	
	if (rotate) {
		new_scale.x = no_scale_h ? 1 : dst_h / src_w;
		new_scale.y = no_scale_w ? 1 : dst_w / src_h;
	} else {
		new_scale.x = no_scale_w ? 1 : dst_w / src_w;
		new_scale.y = no_scale_h ? 1 : dst_h / src_h;
	}
	if (old_scale.x < 0) {
		new_scale.x = -new_scale.x;
	}
	if (old_scale.y < 0) {
		new_scale.y = -new_scale.y;
	}
	SysTransform::SetScale(world, grid, new_scale);

	auto pos = SysTransform::GetPosition(world, grid);
	auto offset = SysTransform::GetOffset(world, grid);
	SysTransform::SetPosition(world, grid, pos + sm::rotate_vector(offset, angle) - offset);
}

sm::vec2 CompScale9::GetChildSize(const ecsx::World& world, Scale9Idx idx) const
{
	if (idx < 0 || idx >= 9 || grids[idx].IsNull()) {
		return sm::vec2(0, 0);
	}

	auto& cbb = world.GetComponent<CompBoundingBox>(grids[idx]);
	return sm::vec2(cbb.rect.Width(), cbb.rect.Height());
}

float CompScale9::GetLeftWidth(const ecsx::World& world) const
{
	return sz_left == 0 ?
		std::max(std::max(GetChildSize(world, S9_DOWN_LEFT).x, GetChildSize(world, S9_MID_LEFT).x), GetChildSize(world, S9_TOP_LEFT).x) : sz_left;
}

float CompScale9::GetRightWidth(const ecsx::World& world) const
{
	return sz_right == 0 ?
		std::max(std::max(GetChildSize(world, S9_DOWN_RIGHT).x, GetChildSize(world, S9_MID_RIGHT).x), GetChildSize(world, S9_TOP_RIGHT).x) : sz_right;
}

float CompScale9::GetDownHeight(const ecsx::World& world) const
{
	return sz_down == 0 ?
		std::max(std::max(GetChildSize(world, S9_DOWN_LEFT).y, GetChildSize(world, S9_DOWN_CENTER).y), GetChildSize(world, S9_DOWN_RIGHT).y) : sz_down;
}

float CompScale9::GetTopHeight(const ecsx::World& world) const
{
	return sz_top == 0 ?
		std::max(std::max(GetChildSize(world, S9_TOP_LEFT).y, GetChildSize(world, S9_TOP_CENTER).y), GetChildSize(world, S9_TOP_RIGHT).y) : sz_top;
}

}
#pragma once

#include <painting2/RenderReturn.h>
#include <SM_Matrix2D.h>

namespace e0 { class World; struct Entity; }
namespace ur2 { class Device; class Context; }

namespace e2
{

class RenderParams
{
public:
	sm::Matrix2D mat;

}; // RenderParams

class SysRender
{
public:
	static pt2::RenderReturn Draw(const ur2::Device& dev, ur2::Context& ctx,
        const e0::World& world, const e0::Entity& entity, const RenderParams& rp = RenderParams());

}; // SysRender

}
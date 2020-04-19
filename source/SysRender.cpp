#include "entity2/SysRender.h"
#include "entity2/CompTransform.h"
#include "entity2/CompImage.h"
#include "entity2/CompComplex.h"

#include <entity0/World.h>
#include <entity0/Entity.h>
#include <unirender2/Texture.h>
#include <unirender2/RenderState.h>
#include <painting2/Texture.h>
#include <painting2/RenderSystem.h>

namespace e2
{

pt2::RenderReturn SysRender::Draw(const ur2::Device& dev,
                                  ur2::Context& ctx,
                                  const e0::World& world,
                                  const e0::Entity& entity,
	                              const RenderParams& rp)
{
	if (entity.IsNull()) {
		return pt2::RENDER_NO_DATA;
	}

	pt2::RenderReturn ret = pt2::RENDER_OK;

	RenderParams rp_child(rp);

	// matrix
	auto& cmat = world.GetComponent<CompLocalMat>(entity);
	rp_child.mat = cmat.mat * rp.mat;

	// image
	if (world.HasComponent<CompImage>(entity))
	{
		auto& cimage = world.GetComponent<CompImage>(entity);
		auto& tex = cimage.tex;
		if (tex)
		{
            float w = static_cast<float>(tex->GetWidth());
            float h = static_cast<float>(tex->GetHeight());
            ur2::RenderState rs;
			pt2::RenderSystem::DrawTexture(dev, ctx, rs, tex, sm::rect(w, h), rp_child.mat);
		}
	}
	// complex
	else if (world.HasComponent<CompComplex>(entity))
	{
		auto& ccomplex = world.GetComponent<CompComplex>(entity);
		for (auto& child : *ccomplex.children) {
			SysRender::Draw(dev, ctx, world, child, rp_child);
		}
	}

	return ret;
}

}
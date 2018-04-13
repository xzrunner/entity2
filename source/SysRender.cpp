#include "entity2/SysRender.h"
#include "entity2/CompTransform.h"
#include "entity2/CompImage.h"

#include <ecsx/World.h>
#include <ecsx/Entity.h>
#include <painting2/Texture.h>
#include <painting2/RenderSystem.h>

namespace e2
{

pt2::RenderReturn SysRender::Draw(const ecsx::World& world,
                                  const ecsx::Entity& entity,
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
			auto sz = tex->GetSize();
			pt2::RenderSystem::DrawTexture(*tex, sm::rect(sz.x, sz.y), rp.mat);
		}
	}

	return ret;
}

}
#pragma once

#include <ecsx/Component.h>
#include <ecsx/Entity.h>
#include <painting2/Mesh.h>

namespace e2
{

struct CompMesh : public ecsx::Component
{
	std::unique_ptr<pt2::Mesh<ecsx::Entity>> mesh = nullptr;

}; // CompMesh

}
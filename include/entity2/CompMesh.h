#pragma once

#include <entity0/Component.h>
#include <entity0/Entity.h>
#include <painting2/Mesh.h>

namespace e2
{

struct CompMesh : public e0::Component
{
	std::unique_ptr<pt2::Mesh<e0::Entity>> mesh = nullptr;

}; // CompMesh

}
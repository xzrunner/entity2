#pragma once

#include <entity0/Component.h>
#include <unirender2/typedef.h>

#include <memory>

namespace e2
{

struct CompImage : public e0::Component
{
	ur2::TexturePtr tex = nullptr;

}; // CompImage

}
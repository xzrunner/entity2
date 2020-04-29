#pragma once

#include <entity0/Component.h>
#include <unirender/typedef.h>

#include <memory>

namespace e2
{

struct CompImage : public e0::Component
{
	ur::TexturePtr tex = nullptr;

}; // CompImage

}
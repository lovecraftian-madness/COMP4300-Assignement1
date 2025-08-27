#ifndef CTRANSFORM_HPP
#define CTRANSFORM_HPP

#include "Component.hpp"
#include "Utils/Vec2.hpp"

class CTransform : public Component
{
public:
    Vec2 pos={0,0};
    Vec2 velocity={0,0};
    CTransform();  
    CTransform(const Vec2& p, const Vec2& v) : pos(p), velocity(v){};
};
#endif
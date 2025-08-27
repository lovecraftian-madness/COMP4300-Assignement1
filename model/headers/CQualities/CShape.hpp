#ifndef CTSHAPE_HPP
#define CTSHAPE_HPP

#include "Component.hpp"
#include "Utils/Vec2.hpp"

class CShape : public Component
{
public:
    Vec2 pos={0,0};
    Vec2 velocity={0,0};
    CShape();
    CShape(const Vec2& p, const Vec2& v): pos(p), velocity(v){};
};
#endif
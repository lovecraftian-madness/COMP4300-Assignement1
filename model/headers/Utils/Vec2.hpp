#ifndef VEC2_HPP
#define VEC2_HPP

class Vec2{
public:
    float x=0, y=0;
    Vec2();
    Vec2(float xin, float yin);
    bool operator == (const Vec2& rhs) const;
    bool operator + (const Vec2& rhs) const;
    bool operator * (const Vec2& rhs) const;
    bool operator += (const Vec2& rhs) const;

};

#endif
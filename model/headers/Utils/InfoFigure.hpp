#ifndef INFOFIGURE_HPP
#define INFOFIGURE_HPP

#include <string>

class InfoFigure{
public:
    std::string figure;
    std::string color;
    int xSize;
    int ySize;
    float vx;
    float vy;
    unsigned int red;
    unsigned int green;
    unsigned int blue;
    unsigned int alfa;

    InfoFigure()=default;
    ~InfoFigure()=default;
};
#endif
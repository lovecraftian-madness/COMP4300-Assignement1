#ifndef INFOFONT_HPP
#define INFOFONT_HPP

#include <string>

class InfoFont{
public:
    std::string fontPath;
    int fontSize;
    int redFont, greenFont, blueFont;

    InfoFont()=default;
    ~InfoFont()=default;
};
#endif
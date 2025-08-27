#ifndef FILEINFO_HPP
#define FILEINFO_HPP

#include <fstream>
#include "InfoFigure.hpp"
#include "InfoFont.hpp"
#include "Vec2.hpp"
#include <vector>

class FileInfo{   
public:
    std::string filePath;
    Vec2 window;
    InfoFont font;
    std::vector<InfoFigure> v1;
    
 
    FileInfo():filePath("bin/config.txt"){};
    void setFileToRead(const std::string& filePath);
    void loadFromFile(const std::string& filePath);
};
#endif
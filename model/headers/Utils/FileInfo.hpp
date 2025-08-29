#ifndef FILEINFO_HPP
#define FILEINFO_HPP

#include <fstream>
#include "InfoFigure.hpp"
#include "InfoFont.hpp"
#include <SFML/System/Vector2.hpp>
#include <vector>

class FileInfo{   
public:
    std::string filePath;
    sf::Vector2f window;
    InfoFont font;
    std::vector<InfoFigure> v1;
    
    FileInfo():filePath("bin/config.txt"){};
    void setFileToRead(const std::string& filePath);
    void loadFromFile();
};
#endif
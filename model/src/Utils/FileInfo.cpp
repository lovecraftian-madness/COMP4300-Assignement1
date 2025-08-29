#include "Utils/FileInfo.hpp"

void FileInfo::loadFromFile()
{       
        std::ifstream fin(filePath);
        if (!fin) {
            throw std::runtime_error("Could not open file: " + filePath);
        }

        std::string line;
        if (fin >> line && line == "Window") {
            fin >> window.x >> window.y;   
        }
        if (fin >> line && line == "Font") {
            fin >> this->font.fontPath >> this->font.fontSize
            >>this->font.redFont>>this->font.greenFont>>this->font.blueFont;   
        }

        InfoFigure info;
        while(fin>>info.figure){
            fin>>info.color>>info.xSize>>info.ySize
            >>info.vx>>info.vy>>info.red>>info.green>>info.blue>>info.alfa;
            v1.push_back(info);
        }
};

void FileInfo::setFileToRead(const std::string& filePath) {
    this->filePath = filePath;
};
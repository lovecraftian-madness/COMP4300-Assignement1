#include <SFML/Graphics.hpp>
#include "imgui/imgui.h"
#include "imgui-sfml/imgui-SFML.h"
#include "Utils/FileInfo.hpp"
#include "Utils/FigureFunctions.hpp"
#include <iostream>
#include <memory>
#include <fstream>

int main(int argc, char* argv[]) {
   
    FileInfo infofile;
    infofile.loadFromFile();
        
    sf::RenderWindow window(sf::VideoMode(infofile.window.x, infofile.window.y),
                             "Practice");
    window.setFramerateLimit(60);

    ImGui::SFML::Init(window);

    sf::Clock deltaClock;

    ImGui::GetStyle().ScaleAllSizes(2.0f);
    ImGui::GetIO().FontGlobalScale=2.0f;

    sf::Font myFont;

    if(!myFont.loadFromFile(infofile.font.fontPath)){
        std::cerr<<"Could not load font!\n";
        exit(-1);
    }
 
    
    float c[3]={0.0f,1.0f,1.0f};
    float circleRadius=50;
    int circleSegments=32;
    float circleSpeedX=1.0f;
    float circleSpeedY=.5f;
    bool drawCircle=true;
    bool drawText=true;
    
    char displayString[255]="Sample Text";
    sf::CircleShape circle(circleRadius,circleSegments);
    sf::Text text(displayString, myFont,infofile.font.fontSize);

    {
        circle.setPosition(10.f, 10.f);
        FigureFunctions::centerCircleAndText(circle,text);
    } 

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(window,event);

            if (event.type == sf::Event::Closed){
                window.close();
            }
            if (event.type == sf::Event::KeyPressed){
                std::cout<<"Key pressed with code = " << event.key.code<<"\n";
                if (event.key.code == sf::Keyboard::Enter){
                    circleSpeedX*=-1.0f;
                }
            }
        }

        ImGui::SFML::Update(window, deltaClock.restart());

        {
        ImGui::Begin("Window title");
        ImGui::Text("Window Text!");
        ImGui::Checkbox("Draw Circle", &drawCircle);
        ImGui::SameLine();
        ImGui::Checkbox("Draw Text",&drawText);
        ImGui::SliderFloat("Radius",&circleRadius,0.0f,300.0f);
        ImGui::SliderInt("Sides",&circleSegments,3,64);
        ImGui::SliderFloat("Velocity X",&circleSpeedX,0,10);
        ImGui::SliderFloat("Velocity Y",&circleSpeedY,0,10);
        ImGui::ColorEdit3("Color Circle",c);
        ImGui::InputText("Text", displayString,255);
        if(ImGui::Button("Set Text")){
            text.setString(displayString);
        }
        ImGui::SameLine();
        if(ImGui::Button("Reset")){
            circle.setPosition(0,0);
        }
        ImGui::End();
        }

        circle.setPointCount(circleSegments);
        circle.setRadius(circleRadius);
        circle.setFillColor(sf::Color
            (sf::Uint8(c[0]*255),sf::Uint8(c[1]*255),sf::Uint8(c[2]*255)));

        {
        sf::Vector2f nextPos = circle.getPosition() + 
            sf::Vector2f(circleSpeedX, circleSpeedY);
        
        {
        if (nextPos.x < 0 || nextPos.x + circleRadius * 2 > infofile.window.x) {
            circleSpeedX *= -1;
        }
        if (nextPos.y < 0 || nextPos.y + circleRadius * 2 > infofile.window.y) {
            circleSpeedY *= -1;
        }
        
        circle.setPosition(nextPos);
        text.setPosition(circle.getPosition());
        FigureFunctions::centerCircleAndText(circle,text);
        FigureFunctions::scaleCircleAndText(circle,text);
        }
        }

        window.clear();

        if(drawCircle){
            window.draw(circle);
        }
        if(drawText){
            window.draw(text);
        }

        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();
    return 0;
}

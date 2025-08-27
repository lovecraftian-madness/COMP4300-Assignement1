#include <SFML/Graphics.hpp>
#include "imgui/imgui.h"
#include "imgui-sfml/imgui-SFML.h"

#include <iostream>
#include <memory>
#include <fstream>

int main(int argc, char* argv[]) {
    const int wWidth=1600;
    const int wHeight=860;
    sf::RenderWindow window(sf::VideoMode(wWidth, wHeight), "Practice1");
    window.setFramerateLimit(60);

    ImGui::SFML::Init(window);
    sf::Clock deltaClock;

    ImGui::GetStyle().ScaleAllSizes(2.0f);
    ImGui::GetIO().FontGlobalScale=2.0f;

    float c[3]={0.0f,1.0f,1.0f};
    float circleRadius=50;
    int circleSegments=32;
    float circleSpeedX=1.0f;
    float circleSpeedY=.5f;
    bool drawCircle=true;
    bool drawText=true;

    sf::CircleShape circle(circleRadius,circleSegments);
    circle.setPosition(10.0f,10.0f);

    sf::Font myFont;
    
    if(!myFont.loadFromFile("fonts/tech.ttf")){
        std::cerr<<"Could not load font!\n";
        exit(-1);
    }

    sf::Text text("Sample Text", myFont,32);
    text.setPosition(10,wHeight-(float)text.getCharacterSize()-10);

    char displayString[255]="Sample Text";

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
        if(ImGui::Button("Reset Circle")){
            circle.setPosition(0,0);
        }
        ImGui::End();

        circle.setPointCount(circleSegments);
        circle.setRadius(circleRadius);
        circle.setFillColor(sf::Color(sf::Uint8(c[0]*255),sf::Uint8(c[1]*255),sf::Uint8(c[2]*255)));
        circle.setPosition(circle.getPosition().x+circleSpeedX,circle.getPosition().y+circleSpeedY);
        
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

#include <SFML/Graphics.hpp>
#include "imgui/imgui.h"
#include "imgui-sfml/imgui-SFML.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1280, 720), "ImGui + SFML Test");
    window.setFramerateLimit(60);

    ImGui::SFML::Init(window);

    sf::Clock deltaClock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(event);

            if (event.type == sf::Event::Closed)
                window.close();
        }

        ImGui::SFML::Update(window, deltaClock.restart());

        ImGui::Begin("Hello, ImGui!");
        ImGui::Text("This is a test with ImGui + SFML");
        ImGui::End();

        window.clear();
        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();
    return 0;
}

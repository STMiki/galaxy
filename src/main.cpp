/*
** EPITECH PROJECT, 2019
** main.cpp
** File description:
** Main file of the project.
*/

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Galaxy.hpp"
#include "SolarSystem.hpp"

void update(sf::RenderWindow &window, Galaxy galaxy)
{
    window.clear();
    sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
    uint32_t _x = mouse_pos.x;
    uint32_t _y = mouse_pos.y;

    for (uint32_t y = 0; y <= window.getSize().y + 32; y += 16) {
        for (uint32_t x = 0; x <= window.getSize().x + 32; x += 16) {
            SolarSystem cluster(x + (galaxy.getOffset().x - (galaxy.getOffset().x % 16)),
                                y + (galaxy.getOffset().y - (galaxy.getOffset().y % 16)));

            if (!cluster.exists()) continue;

            sf::CircleShape pixel(cluster.getSize() / 2);

            pixel.setPosition(sf::Vector2f((double)x - (double)(galaxy.getOffset().x % 16) - 16,
                                            (double)y - (double)(galaxy.getOffset().y % 16) - 16));
            pixel.setFillColor(cluster.getColor());
            window.draw(pixel);

            // outline
            if (((x - 16)) != _x - (_x % 16) ||
                ((y - 16)) != _y - (_y % 16))
                continue;

            sf::CircleShape outline;

            outline.setFillColor(sf::Color::Transparent);
            outline.setOutlineColor(cluster.getColor());
            outline.setOutlineThickness(1);
            outline.setRadius((cluster.getSize() / 2) + 4);
            outline.setOrigin(outline.getRadius() / 2, outline.getRadius() / 2);
            outline.setPosition(sf::Vector2f((double)x - (double)(galaxy.getOffset().x % 16) - 16,
                                            (double)y - (double)(galaxy.getOffset().y % 16) - 16));
            window.draw(outline);
        }
    }
    window.display();
}

int main(int argc, const char *argv[])
{
    bool autoscroll = false;
    (void)argv;
    if (argc > 1)
        autoscroll = true;
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Galaxy", (sf::Style::Default ^ sf::Style::Resize) | sf::Style::Fullscreen);
    Galaxy galaxy;
    window.clear(sf::Color::Black);
    window.setVerticalSyncEnabled(true);
    window.display();

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)                                               window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Z)      galaxy.setOffset().y -= 1;
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Q)      galaxy.setOffset().x -= 1;
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S)      galaxy.setOffset().y += 1;
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::D)      galaxy.setOffset().x += 1;
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) window.close();
        }
        if (autoscroll) {
            galaxy.setOffset().x -= 1;
            galaxy.setOffset().y -= 1;
        }
        update(window, galaxy);
    }
    return (0);
}

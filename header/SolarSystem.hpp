/*
** PERSONNAL PROJECT, 2020
** galaxy
** File description:
** SolarSystem
*/

#ifndef SOLARSYSTEM_HPP_
#define SOLARSYSTEM_HPP_

#include <SFML/Graphics.hpp>
#include <vector>
#include <random>

class SolarSystem {
	public:
		SolarSystem(uint32_t x, uint32_t y, bool full_generation = false);
		~SolarSystem();
        int randInt(int min, int max);
        double randDouble(double min, double max);
        bool exists() const;
        uint32_t Lehmer32();

        sf::Color getColor() const;
        void setColor(sf::Color _color);
        uint8_t getSize() const;
        void setSize(uint8_t _size);

        // void drawStar(sf::RenderWindow &window, sf::Vector2i offset);

	private:
        sf::Vector2u _view_pos;
        sf::Shape *_pixel;
        sf::Color _color;
        uint8_t _size = 16;
        uint32_t nLehmer = 0;
        bool _exists = false;
};

#endif /* !SOLARSYSTEM_HPP_ */

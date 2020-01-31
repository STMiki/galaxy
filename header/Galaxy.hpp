/*
** PERSONAL PROJECT, 2020
** galaxy
** File description:
** Galaxy
*/

#ifndef GALAXY_HPP_
#define GALAXY_HPP_

#include <SFML/Graphics.hpp>
#include "SolarSystem.hpp"

class Galaxy
{
    public:
        Galaxy(sf::Vector2i view_offset = sf::Vector2i(0, 0));
        ~Galaxy();
        sf::Vector2i getOffset() const;
        sf::Vector2i &setOffset();

	private:
        sf::Vector2i _view_offset;
};

#endif /* !GALAXY_HPP_ */

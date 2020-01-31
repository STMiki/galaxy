/*
** PERSONNAL PROJECT, 2020
** galaxy
** File description:
** Galaxy
*/

#include "Galaxy.hpp"
#include "SolarSystem.hpp"

Galaxy::Galaxy(sf::Vector2i view_offset): _view_offset(view_offset)
{
}

Galaxy::~Galaxy()
{
}

sf::Vector2i Galaxy::getOffset() const
{
    return (this->_view_offset);
}

sf::Vector2i &Galaxy::setOffset()
{
    return (this->_view_offset);
}

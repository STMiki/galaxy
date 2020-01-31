/*
** EPITECH PROJECT, 2020
** galaxy
** File description:
** SolarSystem
*/

#include <SFML/Graphics.hpp>
#include <iostream>
#include "SolarSystem.hpp"

const sf::Color STARS_COLORS[] = {
    sf::Color::Blue,
    sf::Color::Red,
    sf::Color::Green,
    sf::Color::Magenta,
    sf::Color::Yellow,
    sf::Color::Cyan,
    sf::Color(183, 60, 32),
    sf::Color(43, 23, 65)
};

SolarSystem::SolarSystem(uint32_t x, uint32_t y, bool full_generation)
{
    this->nLehmer = (x & 0xFFFF) << 16 | (y & 0xFFFF);
    this->_exists = this->randInt(1, 20) == 1;

    if (!this->_exists) return;
    this->_color = STARS_COLORS[this->randInt(0, 7)];
    this->_size = randInt(2, 16);
    (void)full_generation;
}

SolarSystem::~SolarSystem()
{
}

uint32_t SolarSystem::Lehmer32()
{
    this->nLehmer += 0xe120fc15;
    uint64_t tmp;
    tmp = (uint64_t)this->nLehmer * 0x4a39b70d;
    uint32_t m1 = (tmp >> 32) ^ tmp;
    tmp = (uint64_t)m1 * 0x12fad5c9;
    uint32_t m2 = (tmp >> 32) ^ tmp;
    return (m2);
}

double SolarSystem::randDouble(double min, double max)
{
    return (((double)this->Lehmer32() / (double)(0x7FFFFFFF)) * (max - min) + min);
}

// void SolarSystem::drawStar(sf::RenderWindow &window, sf::Vector2i offset)
// {
// }

int SolarSystem::randInt(int min, int max)
{
    int result = (this->Lehmer32() % (max - min)) + min;
    return (result);
}

bool SolarSystem::exists() const
{
    return this->_exists;
}

sf::Color SolarSystem::getColor() const
{
    return this->_color;
}

void SolarSystem::setColor(sf::Color _color)
{
    this->_color = _color;
}

uint8_t SolarSystem::getSize() const
{
    return this->_size;
}

void SolarSystem::setSize(uint8_t _size)
{
    this->_size = _size;
}

#include "bricks.hpp"

namespace bricks {

Bricks::Bricks(const sf::Color& a_color, float a_width, float a_height, float a_xPos, float a_yPos, int a_strength)
: BricksBase(a_color, a_width, a_height, a_xPos, a_yPos)
, m_strength(a_strength)
{}


int Bricks::Strength()
{
    return m_strength;
}


void Bricks::DecrementStrength()
{
    --m_strength;
}


} //bricks
#include "bricks_base.hpp"

namespace bricks {


BricksBase::BricksBase(const sf::Color& a_color, float a_width, float a_height, float a_xPos, float a_yPos)
: m_brick(sf::Vector2f(a_width, a_height))
{
    SetShapeColor(m_brick, a_color);
    SetShapePosition(m_brick, a_xPos, a_yPos);
}


const sf::Vector2f BricksBase::GetPosition() const
{
    return m_brick.getPosition();
}


void BricksBase::Draw(sf::RenderWindow& a_screen) const
{
    a_screen.draw(m_brick);
}


sf::FloatRect BricksBase::GetGlobalBounds() const
{
    return m_brick.getGlobalBounds();
}


} //bricks
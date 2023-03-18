#include "paddle.hpp"

namespace bricks {

Paddle::Paddle()
: BricksBase()
{}


Paddle::Paddle(const sf::Color& a_color, float a_width, float a_height, float a_xPos, float a_yPos, float a_xOffset, float a_yOffset)
: BricksBase(a_color, a_width, a_height, a_xPos, a_yPos)
, m_xOffset(a_xOffset)
, m_yOffset(a_yOffset)
{}


void Paddle::Move(sf::Event& a_event)
{
    if (a_event.key.code == sf::Keyboard::Right && GetPosition().x <= 600) {
        m_xOffset += 1;
        m_brick.move(m_xOffset, 0);
    }
    else if (a_event.key.code == sf::Keyboard::Left && GetPosition().x > 0) {
        m_yOffset -= 1;
        m_brick.move(m_yOffset, 0);
    }
}


} //bricks
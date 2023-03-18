#include "ball.hpp"

namespace bricks {

Ball::Ball()
: Shape()
{}


Ball::Ball(const sf::Color& a_color, float a_radius, float a_xPos, float a_yPos, float a_xOffset, float a_yOffset)
: m_ball(a_radius)
, m_xOffset(a_xOffset)
, m_yOffset(a_yOffset)
{
    SetShapeColor(m_ball, a_color);
    SetShapePosition(m_ball, a_xPos, a_yPos);
}


const sf::Vector2f Ball::GetPosition() const
{
    return m_ball.getPosition();
}


void Ball::Draw(sf::RenderWindow& a_screen) const
{
    a_screen.draw(m_ball);
}


sf::FloatRect Ball::GetGlobalBounds() const
{
    return m_ball.getGlobalBounds();
}


void Ball::Move()
{
    m_ball.move(m_xOffset, m_yOffset);
}


void Ball::ChangeDirection(enum MovingDirection a_direction)
{
    if (a_direction == HORIZONTAL) {
        m_xOffset *= (-1);
    }
    else if (a_direction == VERTICAL){
        m_yOffset *= (-1);
    }
}


} //bricks

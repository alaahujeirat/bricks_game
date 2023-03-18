#ifndef BALL_HPP
#define BALL_HPP

#include "shape.hpp"
#include "directions.hpp"

namespace bricks {

class Ball: public Shape {
public:
    Ball();
    Ball(const sf::Color& a_color, float a_radius, float a_xPos, float a_yPos, float a_xOffset, float a_yOffset);
    Ball(Ball const& a_other) = default;
    Ball& operator=(Ball const& a_other) = default;
    ~Ball() = default;

    const sf::Vector2f GetPosition() const override;
    void Draw(sf::RenderWindow& a_screen) const override;
    sf::FloatRect GetGlobalBounds() const override;

    void Move();
    void ChangeDirection(enum MovingDirection a_direction);

private:
    sf::CircleShape m_ball;
    float m_xOffset;
    float m_yOffset;
};

} //bricks

#endif
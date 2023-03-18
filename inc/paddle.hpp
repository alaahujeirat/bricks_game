#ifndef PADDLE_HPP
#define PADDLE_HPP

#include "bricks_base.hpp"

namespace bricks {

class Paddle: public BricksBase {
public:
    Paddle();
    Paddle(const sf::Color& a_color, float a_width, float a_height, float a_xPos, float a_yPos, float a_xOffset, float a_yOffset);
    Paddle(Paddle const& a_other) = default;
    Paddle& operator=(Paddle const& a_other) = default;
    ~Paddle() = default;

    void Move(sf::Event& a_event);

private:
    float m_xOffset;
    float m_yOffset; //???
};

} //bricks

#endif
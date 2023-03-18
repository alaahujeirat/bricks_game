#ifndef BRICKS_HPP
#define BRICKS_HPP

#include "bricks_base.hpp"

namespace bricks {

class Bricks: public BricksBase {
public:
    Bricks(const sf::Color& a_color, float a_width, float a_height, float a_xPos, float a_yPos, int a_strength);
    Bricks(Bricks const& a_other) = default;
    Bricks& operator=(Bricks const& a_other) = default;
    ~Bricks() = default;

    int Strength();
    void DecrementStrength();

private:
    int m_strength;
};

} //bricks

#endif
#ifndef BRICKS_BASE_HPP
#define BRICKS_BASE_HPP

#include "shape.hpp"

namespace bricks {

class BricksBase: public Shape {
public:
    BricksBase() = default;
    BricksBase(const sf::Color& a_color, float a_width, float a_height, float a_xPos, float a_yPos);
    BricksBase(BricksBase const& a_other) = default;
    BricksBase& operator=(BricksBase const& a_other) = default;
    ~BricksBase() = default;

    const sf::Vector2f GetPosition() const override;
    void Draw(sf::RenderWindow& a_screen) const override;
    sf::FloatRect GetGlobalBounds() const override;

protected:
    sf::RectangleShape m_brick;
};

} //bricks

#endif
#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <SFML/Graphics.hpp>
#include "abstract_shape.hpp"
#include "screen_manager.hpp"

namespace bricks {

class Shape: public AbstractShape {
public:
    Shape() = default;
    Shape(sf::Shape* a_shape, const sf::Color& a_color, float a_xPos, float a_yPos);
    Shape(Shape const& a_other) = default;
    Shape& operator=(Shape const& a_other) = default;
    ~Shape() = default;

    void SetShapeColor(sf::Shape& a_shape, const sf::Color& a_color) override;
    void SetShapePosition(sf::Shape& a_shape, float a_x, float a_y) override;

    virtual const sf::Vector2f GetPosition() const = 0;
    virtual void Draw(sf::RenderWindow& a_screen) const = 0;
    virtual sf::FloatRect GetGlobalBounds() const = 0;
};

} //bricks

#endif
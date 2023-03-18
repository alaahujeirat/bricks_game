#include "shape.hpp"

namespace bricks {

void Shape::SetShapeColor(sf::Shape& a_shape, const sf::Color& a_color)
{
    a_shape.setFillColor(a_color);
}


void Shape::SetShapePosition(sf::Shape& a_shape, float a_x, float a_y)
{
    a_shape.setPosition(a_x, a_y);
}


} //bricks
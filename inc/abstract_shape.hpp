#ifndef ABSTRACT_SHAPE_HPP
#define ABSTRACT_SHAPE_HPP

#include <SFML/Graphics.hpp>

namespace bricks {

class AbstractShape  {
public:
    virtual ~AbstractShape() = default;
    virtual void SetShapeColor(sf::Shape& a_shape, const sf::Color& a_color) = 0;
    virtual void SetShapePosition(sf::Shape& a_shape, float a_x, float a_y) = 0;

protected:
    AbstractShape() = default;
    AbstractShape(AbstractShape const& a_other) = default;
    AbstractShape& operator=(AbstractShape const& a_other) = default;
};

} //bricks

#endif
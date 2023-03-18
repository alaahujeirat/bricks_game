#include <algorithm>
#include "screen_manager.hpp"

namespace bricks {

Screen::Screen(unsigned int a_width, unsigned int a_height, const sf::String& a_title)
: m_screen(sf::VideoMode(a_width, a_height), a_title)
{}


bool Screen::IsOpen() const
{
    return m_screen.isOpen();
}


bool Screen::PollEvent(sf::Event& a_event)
{
    return m_screen.pollEvent(a_event);
}


void Screen::Clear(const sf::Color& a_color)
{
    m_screen.clear(a_color);
}


void Screen::Draw(sf::Drawable& a_shape)
{
    m_screen.draw(a_shape);
    
    
}


void Screen::Display()
{
    m_screen.display();
}


void Screen::Close()
{
    m_screen.close();
}


sf::RenderWindow& Screen::GetScreen()
{
    return m_screen;
}

} //bricks
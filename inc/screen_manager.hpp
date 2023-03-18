#ifndef SCREEN_MANAGER_HPP
#define SCREEN_MANAGER_HPP

#include <SFML/Graphics.hpp>

namespace bricks {

class Screen {
public:
    Screen(unsigned int a_width, unsigned int a_height, const sf::String& a_title);
    Screen(Screen const& a_other) = default;
    Screen& operator=(Screen const& a_other) = default;
    ~Screen() = default;

    bool IsOpen() const;
    bool PollEvent(sf::Event& a_event);
    void Clear(const sf::Color& a_color = sf::Color(0, 0, 0, 255));
    void Draw(sf::Drawable& a_shape);
    void Display();
    void Close();

    sf::RenderWindow& GetScreen();

private:
    sf::RenderWindow m_screen;
};

    
} //bricks

#endif
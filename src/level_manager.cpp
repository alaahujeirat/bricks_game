#include <fstream>
#include <map>
#include "level_manager.hpp"
#include "directions.hpp"

namespace bricks {


Level::Level(std::fstream& a_stream)
: m_ball()
, m_paddle()
, m_bricks()
{
    InitMembers(a_stream);
}

 
static std::map<std::string, sf::Color> ColorCatalog()
{
    std::map<std::string, sf::Color> colors;
    
    colors.insert({"Black", sf::Color::Black});
    colors.insert({"Blue", sf::Color::Blue});
    colors.insert({"Green", sf::Color::Green});
    colors.insert({"Red", sf::Color::Red});
    colors.insert({"Magenta", sf::Color::Magenta});
    colors.insert({"White", sf::Color::White});
    colors.insert({"Cyan", sf::Color::Cyan});

    return colors;
}


static Ball InitBall(std::fstream& a_stream, std::map<std::string, sf::Color>& a_colors)
{
    float radius, x, y, xOffset, yOffset;
    std::string color;

    a_stream >> radius;
    a_stream >> color;
    sf::Color sf_color = a_colors.find(color)->second;
    a_stream >> x >> y >> xOffset >> yOffset;

    return Ball(sf_color, radius, x, y, xOffset, yOffset);
}


static Paddle InitPaddle(std::fstream& a_stream, std::map<std::string, sf::Color>& a_colors)
{
    float width, height, x, y, xOffset, yOffset;
    std::string color;

    a_stream >> width >> height;
    a_stream >> color;
    sf::Color sf_color = a_colors.find(color)->second;
    a_stream >> x >> y >> xOffset >> yOffset;
    
    return Paddle(sf_color, width, height, x, y, xOffset, yOffset);
}


static std::vector<Bricks> InitBricks(std::fstream& a_stream, std::map<std::string, sf::Color>& a_colors)
{
    std::vector<Bricks> vec;
    std::vector<Bricks>::size_type num_of_bricks;
    a_stream >> num_of_bricks;

    while (vec.size() < num_of_bricks) {
        float width, height, x, y;
        std::string color;
        int strength;

        a_stream >> width >> height;
        a_stream >> color;
        sf::Color sf_color = a_colors.find(color)->second;
        a_stream >> x >> y >> strength;
        
        vec.push_back(Bricks(sf_color, width, height, x, y, strength));
    }

    return vec;
}


void Level::InitMembers(std::fstream& a_stream)
{
    std::map<std::string, sf::Color> colors_catalog = ColorCatalog();
    
    m_ball = InitBall(a_stream, colors_catalog);
    m_paddle = InitPaddle(a_stream, colors_catalog);
    m_bricks = InitBricks(a_stream, colors_catalog);
}


bool Level::Run(Screen& a_screen)
{
    while (a_screen.IsOpen()) {
        sf::Event event;
        while (a_screen.PollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                a_screen.Close();
            }
            else if (event.type == sf::Event::KeyPressed) {
                m_paddle.Move(event);
            }

            DisplayScreen(a_screen);

            m_ball.Move();
            
            if (IsLevelOver()) {
                a_screen.Close();
                return false;
            }
            else if (LevelWon()) {
                a_screen.Close();
                break;
            }

            HandleCollision();

        }
    }
    return true;
}


void Level::DisplayScreen(Screen& a_screen) const
{
    a_screen.Clear();

    m_ball.Draw(a_screen.GetScreen());
    m_paddle.Draw(a_screen.GetScreen());
    for (auto e: m_bricks) {
        e.Draw(a_screen.GetScreen());
    }

    a_screen.Display();
}


static void HandlePaddleCollision(Ball& a_ball, Paddle& a_paddle)
{
    if (a_ball.GetPosition().x <= 0 || a_ball.GetPosition().x >= 780) {
        a_ball.ChangeDirection(HORIZONTAL);
    }
    else if (a_ball.GetPosition().y <= 0 || a_ball.GetGlobalBounds().intersects(a_paddle.GetGlobalBounds())) {
        a_ball.ChangeDirection(VERTICAL);
    }
}

static void HandleBrickCollision(Ball& a_ball, std::vector<Bricks>& a_bricks)
{
    std::vector<Bricks>::iterator it = a_bricks.begin();
    std::vector<Bricks>::iterator end = a_bricks.end();
    while (it != end) {
        Bricks b = *it;
        if (a_ball.GetGlobalBounds().intersects(b.GetGlobalBounds())) {
            if ((*it).Strength() == 0) {
                a_bricks.erase(it);
            }
            else {
                (*it).DecrementStrength();
            }
            a_ball.ChangeDirection(VERTICAL);
        }
        ++it;
    }
}

void Level::HandleCollision()
{
    HandlePaddleCollision(m_ball, m_paddle);
    HandleBrickCollision(m_ball, m_bricks);
}


bool Level::IsLevelOver()
{
    if (m_ball.GetPosition().y >= 600) {
       return true;
    }

    return false;
}


bool Level::LevelWon()
{
    if (m_bricks.empty()) {
        return true;
    }
    return false;
}


} //bricks
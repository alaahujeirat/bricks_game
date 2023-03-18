#ifndef LEVEL_MANAGER_HPP
#define LEVEL_MANAGER_HPP

#include <list>
#include <string>
#include "bricks.hpp"
#include "ball.hpp"
#include "paddle.hpp"
#include "screen_manager.hpp"

namespace bricks {

class Level {
public:
    Level(std::fstream& a_stream);
    Level(Level const& a_other) = default;
    Level& operator=(Level const& a_other) = default;
    ~Level() = default;
    
    bool Run(Screen& a_screen);

private:
    void InitMembers(std::fstream& a_stream);
    void DisplayScreen(Screen& a_screen) const;
    void HandleCollision();
    bool IsLevelOver();
    bool LevelWon();

private:
    Ball m_ball;
    Paddle m_paddle;
    std::vector<Bricks> m_bricks;
};
    
} //bricks

#endif
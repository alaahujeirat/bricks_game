#ifndef GAME_MANAGER_HPP
#define GAME_MANAGER_HPP

#include <string>

namespace bricks {

class Game {
public:
    Game() = default;
    Game(Game const& a_other) = default;
    Game& operator=(Game const& a_other) = default;
    ~Game() = default;

    void Run(const char* a_filename);
};

} //bricks

#endif
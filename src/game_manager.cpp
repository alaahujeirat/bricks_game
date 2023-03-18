#include <fstream>
#include"game_manager.hpp"
#include "level_manager.hpp"
#include "screen_manager.hpp"

namespace bricks {


void Game::Run(const char* a_filename)
{
    std::fstream f(a_filename);

    std::string screen_title;
    while (f >> screen_title) {
        Screen screen(800, 600, screen_title);
        Level level(f);
        if (!level.Run(screen)) {
            break;
        }
    }
}


} //bricks
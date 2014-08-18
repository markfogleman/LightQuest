#ifndef _lq_game_hpp_
#define _lq_game_hpp_

#include <stdint.h>
#include "player.hpp"
#include "galaxy.hpp"
#include "timekeeper.hpp"

// An instance of the game.  This contains the references to the high level
// abstractions of the game like the galaxy and the players.
class game {

  public:
    game(void);
    player* getPlayer(uint32_t ID);
    galaxy* getGalaxy(void);

  private:
    galaxy the_galaxy;
    std::vector<player> player_list;

};

#endif


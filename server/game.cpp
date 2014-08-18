#include <stdint.h>
#include "game.hpp"
#include "player.hpp"

game::game(void)
{
  for (uint32_t i = 1; i <= 2; ++i) {
    player_list.push_back(player(i));
  }
}

player* game::getPlayer(uint32_t ID)
{
  return &player_list[ID];
}

galaxy* game::getGalaxy(void)
{
  return &the_galaxy;
}


#include <stdint.h>
#include "game.hpp"
#include "player.hpp"

game::game(void) : player1(1), player2(2)
{
}

player* game::getPlayer(uint32_t ID)
{
  player* output = &player1;
  if (ID == 2) {
    output = &player2;
  }
  return output;
}

galaxy* game::getGalaxy(void)
{
  return &the_galaxy;
}


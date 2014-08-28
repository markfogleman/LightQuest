#include <cmath>
#include <iostream>
#include "galaxy.hpp"
#include "game.hpp"
#include "random_gen.hpp"

void init_Galaxy(game* theGame)
{
  // Create all of the planets with any initial properties
  galaxy* theGalaxy = theGame->getGalaxy();
  theGalaxy->createPlanets(50);

}

// This is the initialization for the game instance
game* init_Game(void)
{
  std::cout << "Welcome to LightQuest!!!" << std::endl;
  game* theGame = new game; 
  player* player1 = theGame->getPlayer(1);
  player* player2 = theGame->getPlayer(2);

  player1->assignName("Mark");
  player2->assignName("Sadaf");
  
  return theGame;

}

void initHQPlanets(game* theGame)
{
  // Make sure that the initial planets are at least half a galaxy apart
  galaxy* theGalaxy = theGame->getGalaxy();
  std::pair<double, double> Xbounds = theGalaxy->getXBounds();
  std::pair<double, double> Ybounds = theGalaxy->getYBounds();
  double xdist = Xbounds.second-Xbounds.first;
  double ydist = Ybounds.second-Ybounds.first;

  double diagonal = sqrt(pow(xdist, 2.0) + pow(ydist, 2.0));
  uint32_t numplanets = theGalaxy->getNumPlanets();
  std::vector<std::vector<double> > dist_matrix = theGalaxy->getDistMatrix();
  while (true) {
    uint32_t test1 = get_random_int(0, numplanets);
    uint32_t test2 = get_random_int(0, numplanets);
    double loc_dist = dist_matrix[test1][test2];
    // The equality test is probably redundant
    if ((loc_dist > (diagonal/2.0)) && (test1 != test2)) {
      // The planets are far enough apart, asign them to the HG
      player* player1 = theGame->getPlayer(1);
      player* player2 = theGame->getPlayer(2);
      player1->addToPlanetsOwned(test1);
      player2->addToPlanetsOwned(test2);
      break;
    }
  }

}


int main(int argc, char** argv) {
  
  game* theGame = init_Game();

  init_Galaxy(theGame);

  theGame->getPlayer(1)->updateGalaxy(theGame->getGalaxy());
  theGame->getPlayer(2)->updateGalaxy(theGame->getGalaxy());

  initHQPlanets(theGame);

  std::cout << "Thanks for playing!" << std::endl;

  return 0;
}


#ifndef _lq_player_hpp_
#define _lq_player_hpp_

#include <stdint.h>
#include <string>
#include <vector>
#include "ship.hpp"
#include "galaxy.hpp"

class player
{
  public:
    player(uint32_t _id) : ID(_id), sight_range(50.0) {}
    uint32_t getID(void) const;
    void controlLoop(void);
    void researchLoop(void);
    void researchShips(void);
    void displayPlanets(void) const;
    void displayResearch(void) const;
    void assignName(std::string);    
    std::string getName(void) const;
    double getSightRange(void) const;
    void updatePlanetsSeen(void);    
    void addToPlanetsOwned(uint32_t _id);
    void removeFromPlanetsOwned(uint32_t _id);
    void updateGalaxy(galaxy* _galaxy);

  private:
    unsigned int ID;
    std::vector<scout> scouts;
    std::string name;
    double sight_range;
    std::vector<bool> planets_seen;
    std::vector<bool> planets_owned;
    galaxy* the_galaxy;

    // TODO: Need a data structure that holds the planets that the player
    // has current visibility of as well as the planets that they control.
    // Perhaps just a vector of bools that maps back to the galaxy planet
    // list?
};

#endif


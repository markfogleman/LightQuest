#include <iostream>
#include <stdint.h>
#include <string>
#include "player.hpp"

uint32_t player::getID(void) const
{
  return ID;
}

void player::displayPlanets(void) const
{
  std::cout << "You currently control the following planets:" << std::endl;
  for (uint32_t i = 0; i<planets_owned.size(); ++i) {
    if (planets_owned[i] == true) {
      //TODO: Add locations here
      std::cout << i << std::endl;
    }
  }
  std::cout << "You can currently see " << sight_range << " light-minutes "
    "from each of your colonies." << std::endl;
  std::cout << "You current see the following planets:" << std::endl;
  for (uint32_t i = 0; i < planets_seen.size(); ++i) {
    if (planets_seen[i] == true) {
      std::cout << i << std::endl;
    }
  }
    
}

void player::displayResearch(void) const
{
  std::cout << "Show all of the research options and status." << std::endl;
}

void player::assignName(std::string _name)
{
  name = _name;
}

std::string player::getName(void) const
{
  return name;
}

void player::researchShips(void)
{
  std::string command_input;
  std::cout << "Welcome to the ship engineering gorup." << std::endl;
  while (true) {
    std::cout << "Give a command: ";
    std::cin >> command_input;
    if ((command_input == "help") || (command_input == "h")) {
      std::cout << "Options include:" << std::endl;
      std::cout << "Display status(s)" << std::endl;
      std::cout << "Research ship type (1-n)" << std::endl;
      std::cout << "Return to main research lab(c)" << std::endl;
    } else if (command_input == "c") {
      break;
    } else {
      std::cout << "Command not recognized." << std::endl;
    }
  }
}

double player::getSightRange(void) const
{
  return sight_range;
}

void player::addToPlanetsOwned(uint32_t _id)
{
  planets_owned[_id] = true;
  updatePlanetsSeen();
}

void player::removeFromPlanetsOwned(uint32_t _id)
{
  planets_owned[_id] = false;
  updatePlanetsSeen();
}

void player::updateGalaxy(galaxy* _galaxy)
{
  the_galaxy = _galaxy;
  // Set the planet lists at the same time
  uint32_t num_planets = the_galaxy->getNumPlanets();
  for (uint32_t i = 0; i < num_planets; ++i) {
    planets_owned.push_back(false);
    planets_seen.push_back(false);
  }
}

void player::updatePlanetsSeen(void)
{
  //TODO: put in a check to make sure at least one planet is owned
  //TODO: calculating this the brain-dead way, think of a smarter way later
  // Reset all seen to zero
  for (uint32_t i = 0; i < planets_seen.size(); ++i) {
    planets_seen[i] = false;
  }
  std::vector<std::vector<double> > dist_matrix = the_galaxy->getDistMatrix();
  for (uint32_t i = 0; i < planets_owned.size(); ++i) {
    for (uint32_t j = 0; j < planets_owned.size(); ++j) {
      if (planets_owned[i]) {
        if (dist_matrix[i][j] < sight_range) {
          planets_seen[j] = true;
        }
      }
    }
  }

}


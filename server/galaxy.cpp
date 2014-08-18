#include <stdint.h>
#include "galaxy.hpp"
#include "planet.hpp"


void galaxy::createPlanets(uint32_t num)
{
  num_planets = num;
  for (uint32_t i = 0; i < num; ++i) {
    planet_list.push_back(planet(i, x_boundaries, y_boundaries));
  }
  for (uint32_t i = 0; i < num; ++i) {
    std::vector<double> loc_vec(num);
    for (uint32_t j = 0; j < num; ++j) {
      loc_vec[j] = planet_list[i].calc_distance(planet_list[j]);
    }  
    dist_matrix.push_back(loc_vec);
  }

}

uint32_t galaxy::getNumPlanets(void)
{
  return num_planets;
}

std::pair<double, double> galaxy::getXBounds(void)
{
  return x_boundaries;
}

std::pair<double, double> galaxy::getYBounds(void)
{
  return y_boundaries;
}

double galaxy::getSpeedOfLight(void)
{
  return speed_of_light;
}

std::vector<std::vector<double> > galaxy::getDistMatrix(void)
{
  return dist_matrix;
}


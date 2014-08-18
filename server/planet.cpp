#include <iostream>
#include <cmath>
#include "planet.hpp"
#include "random_gen.hpp"

planet::planet(uint32_t _id, std::pair<double, double> xbounds,
  std::pair<double, double> ybounds) : ID(_id)
{
  double xorig = xbounds.first;
  double xend = xbounds.second;
  double yorig = ybounds.first;
  double yend = ybounds.second;

  coords.first = get_random_uniform(xorig, xend);
  coords.second = get_random_uniform(yorig, yend);

}

double planet::calc_distance(const planet& other) const
{
  std::pair<double, double> other_coords = other.getCoords();
  
  return sqrt(pow(other_coords.first - coords.first, 2.0) +
    pow(other_coords.second - coords.second, 2.0));
  
}

std::pair<double, double> planet::getCoords(void) const
{
  return coords;
}

void planet::display_attributes(void) const
{
  std::cout << "Planet " << ID << " is located at (" << coords.first << "," <<
  coords.second << ")" << std::endl;
}


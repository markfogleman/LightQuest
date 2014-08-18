#ifndef _lq_galaxy_hpp_
#define _lq_galaxy_hpp_

#include <stdint.h>
#include <vector>
#include "planet.hpp"

class galaxy {
  public:
    galaxy(void) : x_boundaries(std::pair<double, double>(0.0, 100.0)),
    y_boundaries(std::pair<double, double>(0.0, 100.0)){}
    void createPlanets(uint32_t num);
    std::vector<planet>& getPlanets(void);
    double getSpeedOfLight(void);
    std::pair<double, double> getXBounds(void);
    std::pair<double, double> getYBounds(void);
    uint32_t getNumPlanets(void);
    std::vector<std::vector<double> > getDistMatrix(void);

  private:
    uint32_t num_planets;
    std::pair<double, double> x_boundaries;
    std::pair<double, double> y_boundaries;
    std::vector<planet> planet_list;
    double speed_of_light;
    std::vector<std::vector<double> > dist_matrix;


};

#endif


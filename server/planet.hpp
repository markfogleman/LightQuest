#ifndef _lq_planet_hpp_
#define _lq_planet_hpp_

#include <utility>
#include <stdint.h>

class planet {

  public:
    planet(uint32_t _id, std::pair<double, double> xbounds,
      std::pair<double, double> ybounds);
    double calc_distance(const planet& other) const;
    std::pair<double, double> getCoords(void) const;
    void display_attributes(void) const;

  private:
    uint32_t ID;
    std::pair<double, double> coords;
    double pop_growth_rate;
};

#endif


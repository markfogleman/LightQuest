#ifndef _lq_random_gen_hpp_
#define _lq_random_gen_hpp_

#include <random>

inline double get_random_uniform(double beg, double end) 
{
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<double> dist(beg, end);
  return dist(gen);
}

inline uint32_t get_random_int(int low, int high)
{
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<uint32_t> dist(low, high);
  return dist(gen);

}


#endif


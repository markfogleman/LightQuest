#ifndef _lq_timekeeper_hpp_
#define _lq_timekeeper_hpp_

#include <chrono>


class timekeeper
{
  public:
    timekeeper(void) {}
    //TODO: write a function the returns the time since beginning
    void displayTime(void);

  private:
    std::chrono::steady_clock the_clock;
};



#endif


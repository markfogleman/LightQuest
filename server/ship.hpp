#ifndef _lq_ship_hpp_
#define _lq_ship_hpp_

#include <iostream>
#include <stdint.h>

// This is the base class for ship.  All ships should derive from it

class ship {

  public:
    ship(uint32_t _id) : ID(_id) {}
    uint32_t getID(void) { return ID; }
    double getAttack(void) const { return attack_strength; }
    double getDefense(void) const { return defense_strength; }
    double getMass(void) const { return mass; }
    double getThrust(void) const { return thrust; }
    bool getIsTransport(void) const { return is_transport; }
    bool getIsCommand(void) const { return is_command; }
    virtual void printDescription(void) = 0;

  private:
    uint32_t ID;
    double attack_strength;
    double defense_strength;
    double mass;
    double thrust;
    bool is_transport;
    bool is_command;
};


class scout : public ship {
  public:
    scout(uint32_t _id) : ship(_id) {}
    void printDescription(void) {
      std::cout << "This is a scout ship." << std::endl;
    }
};

class warship : public ship {
  public:
    warship(uint32_t _id) : ship(_id) {}
    void printDescription(void) {
      std::cout << "This is a warship." << std::endl;
    }
};

class defender : public ship {
  public:
    defender(uint32_t _id) : ship(_id) {}
    void printDescription(void) {
      std::cout << "This is a defender ship." << std::endl;
    }
};

class command : public ship {
  public:
    command(uint32_t _id) : ship(_id) {}
    void printDescription(void) {
      std::cout << "This is a command ship." << std::endl;
    }
};

class transport : public ship {
  public:
    transport(uint32_t _id) : ship(_id) {}
    void printDescription(void) {
      std::cout << "This is a transport ship." << std::endl;
    }
};


#endif


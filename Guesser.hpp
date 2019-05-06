#pragma once

#include "calculate.hpp"
using std::string;
typedef unsigned int uint;

namespace bullpgia
{
class Guesser
{
  protected:
    uint length;
    string myString;

  public:
    Guesser() { this->myString = ""; }
    virtual string guess() = 0;
    virtual void startNewGame(uint length){};
    virtual void learn(string reply){};
};
}

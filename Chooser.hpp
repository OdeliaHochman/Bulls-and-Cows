#pragma once
#include <iostream>
#include <string>
using std::istream, std::ostream, std::string;
using namespace std;

namespace bullpgia
{
class Chooser
{
protected:
  uint length;

public:
  virtual string choose(uint length) = 0;
};

} // namespace bullpgia

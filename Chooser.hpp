#pragma once
#include <string>
using std::string;
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

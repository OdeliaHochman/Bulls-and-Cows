#pragma once
#include<iostream>
#include<string>
using std::istream,std::ostream, std::string;
using namespace std;

namespace bullpgia 
{
    class Chooser
    {
       public:
       uint length;
      virtual string choose(uint length)=0;
    };

}


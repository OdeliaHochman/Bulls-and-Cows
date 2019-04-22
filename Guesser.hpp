#pragma once

#include<iostream>
//#include<string>
using std::istream,std::ostream, std::string;
typedef unsigned int uint;

namespace bullpgia 
{
    class Guesser
    {
   
       public:
       uint length;
      virtual string guess()=0;
      virtual void startNewGame(uint length);
      virtual void learn (string reply); 
    
    };


};


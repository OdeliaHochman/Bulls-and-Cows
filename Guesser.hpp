#pragma once
#include <string>
using std::string;

namespace bullpgia
{
    class Guesser
    {
        protected:
        int length;
        string cal;

        public:
        virtual void startNewGame(uint length);
        virtual void learn(string cal);
        virtual string guess()=0;
    };


};

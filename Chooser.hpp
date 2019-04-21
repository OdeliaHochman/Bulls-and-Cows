#pragma once
#include <string>
using std::string;

namespace bullpgia
{
    class Chooser
    {
        protected:
        int length;

        public:
        virtual string choose(uint length); //??
    };


};
#pragma once

namespace bullpgia
{
    class Guesser
    {
        private:
        uint length;
        string cal;

        public:
        virtual void startNewGame(uint length);
        virtual void learn(string cal);
        virtual string guess()=0;
    };


};

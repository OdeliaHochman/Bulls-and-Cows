#include "Guesser.hpp"
#include <string>
#include "calculate.hpp"
using std::string;


namespace bullpgia
{
    class SmartGuesser : public bullpgia::Guesser
    {
        void startNewGame(uint length) override;
        void learn(string cal) override;
        string guess() override;
    };

};


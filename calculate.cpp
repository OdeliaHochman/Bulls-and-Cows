#include "calculate.hpp"
using std::string;
#include <string>
#include <sstream> // std::stringstream
using namespace std;

namespace bullpgia
{

string calculateBullAndPgia(string choice, string guess)
{
    int bull = 0;
    int pgia = 0;
    string checkChoice = choice;
    string checkGuess = guess;

    if (choice.length() != guess.length())
    {
        throw("Error!The lengths are not equal");
    }
    else
        for (int i = 0; i < choice.length(); i++)
        {

            if (choice[i] == guess[i])
            {
                checkChoice[i] = 'T';
                checkGuess[i] = 'T';
                bull++;
            }
        }

    for (int i = 0; i < checkChoice.length(); i++)
    {
        for (int j = 0; j < checkGuess.length(); j++)
        {
            if (checkChoice[i] != 'T' && checkGuess[j] != 'T' && checkChoice[i] == checkGuess[j])
            {
                checkChoice[i] = 'T';
                checkGuess[j] = 'T';
                pgia++;
            }
        }
    }

    // std::stringstream bullPgia;
    //  bullPgia>>bull>>pgia;
    //  string ans=bullPgia;
    //         return bullPgia;
    std::string bullPgia = std::to_string(bull) + "," + std::to_string(pgia);

    return bullPgia;
}

}; // namespace bullpgia

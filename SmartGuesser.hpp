#pragma once
#include "Guesser.hpp"
#include "calculate.hpp"
#include <string>
#include <list>
#include <bits/stdc++.h> 
using std::string;

/**
 * SmartGuesser is a guesser that learn to guess the right string
 */
namespace bullpgia
{
class SmartGuesser : public bullpgia::Guesser
{
	std::list<string> perms; // list containing all the permutations of the numbers in the chooser's secret code
	std::list<int> digits; // list containing all the numbers in the chooser's secret code
	int pos; // Position of the guess ( 0-9)
	bool shouldSwap(char str[], int start, int curr);
	void findPermutations( char str[], int index, int n);

  public:
	string guess() override;
	void startNewGame(uint length) override;
	void learn(string reply) override;
};
} 

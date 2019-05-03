#pragma once
#include "Guesser.hpp"
#include "calculate.hpp"
#include <string>
#include <list>
#include <bits/stdc++.h> 


using std::string;
/**
 * ConstantGuesser is a guesser that always guesses the same string. 
 */
namespace bullpgia
{
class SmartGuesser : public bullpgia::Guesser
{
	string mySmartString;
	std::list<string> perms;
	std::list<int> digits;
	int pos;
	bool shouldSwap(char str[], int start, int curr);
	void findPermutations( char str[], int index, int n);

  public:
	SmartGuesser()
	{
		this->mySmartString = "";
	}

	string guess() override;
	void startNewGame(uint length) override;
	void learn(string reply) override;
};
} // namespace bullpgia

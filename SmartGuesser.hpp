#pragma once
#include "Guesser.hpp"
#include<string>
using std::string;
/**
 * ConstantGuesser is a guesser that always guesses the same string. 
 */
 namespace bullpgia
 {
class SmartGuesser: public bullpgia::Guesser 
{
		string mySmartString;
	public:
		SmartGuesser() 
		{		
			this->mySmartString="";	
		 }

		     string guess() override;
			void startNewGame(uint length)override;
            void learn (string reply)override; 
    
};
 }

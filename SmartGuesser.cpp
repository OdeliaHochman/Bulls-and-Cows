#include "SmartGuesser.hpp"
#include "Guesser.hpp"
#include <string>
using std::string;

/**
 * this method guess the string base of the data from learn method
 */
string bullpgia::SmartGuesser::guess()
{
  string ans = "";

  // first step: guess "0000" "1111" "....." until we know all the digits
  if (digits.size() < length)
  {

    for (size_t i = 0; i < length; i++)
    {
      char c = '0' + pos;
      ans += c;
    }

    myString = ans;
    pos++;

    return myString;
  }

  // second step: after we know the digits and all the permutations in perm list
  // we pop from the list the first string

  ans = perms.front(); // access to the first
  perms.pop_front();   // delete the first

  myString = ans;

  return myString;
}

void bullpgia::SmartGuesser::startNewGame(uint length)
{

  this->length = length;
  pos = 0;
  perms.clear();
  digits.clear();
}

/**
 * this method learn from the reply of calculateBullAndPgia what to guess in the next guess
 */
void bullpgia::SmartGuesser::learn(string reply)
{
  bool foundAllDigit = false;
  size_t i = reply.find(',');
  int b = stoi(reply.substr(0, i));                   // bull
  int p = stoi(reply.substr(i + 1, reply.length())); //pgia

  // first step: add to digits list the digits we know
  if (digits.size() < length)
  {

    for (size_t j = 0; j < b; j++)
    {
      digits.push_front(pos - 1);
    }

    if (digits.size() == length)
      foundAllDigit = true;
    else
    {
      return;
    }
  }

  // Happens once, once we have reached the number of digits.
  // We calculate all the permutations and add them to the list
  if (foundAllDigit)
  {

    string ans = "";
    for (std::list<int>::iterator it = digits.begin(); it != digits.end(); ++it)
    {
      char c = '0' + *it;
      ans += c;
    }
    char *chr = strdup(ans.c_str()); // convert from strin to char*

    findPermutations(chr, 0, length); // find the Permutations and add them to perm list

    foundAllDigit = false;
  }
}

/**
 * this algoritim from this site 
 * https://www.geeksforgeeks.org/print-all-permutations-with-repetition-of-characters/ 
 */

// Returns true if str[curr] does not matches with any of the
// characters after str[start]
bool bullpgia::SmartGuesser::shouldSwap(char str[], int start, int curr)
{
  for (int i = start; i < curr; i++)
    if (str[i] == str[curr])
      return 0;
  return 1;
}

// Add to list all distinct permutations in str[0..n-1]
void bullpgia::SmartGuesser::findPermutations(char str[], int index, int n)
{
  if (index >= n)
  {
    perms.push_front(str);
    return;
  }

  for (int i = index; i < n; i++)
  {

    // Proceed further for str[i] only if it
    // doesn't match with any of the characters
    // after str[index]
    bool check = shouldSwap(str, index, i);
    if (check)
    {
      std::swap(str[index], str[i]);
      findPermutations(str, index + 1, n);
      std::swap(str[index], str[i]);
    }
  }
}

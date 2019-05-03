#include "SmartGuesser.hpp"
#include "Guesser.hpp"
#include <string>
using std::string;

string bullpgia::SmartGuesser::guess()
{
  string ans = "";
  if (digits.size() < length)
  {

    for (size_t i = 0; i < length; i++)
    {
      char c = '0' + pos;
      ans += c;
    }

    mySmartString = ans;
    pos++;
  //  std::cout << " the guss is=" << mySmartString << std::endl; //print
   // std::cout << " pos=" << pos << std::endl;

    return mySmartString;
  }

 // std::cout << "in guess after found" << std::endl;

  ans = perms.front(); // access first
  perms.pop_front();   // delete firsr
  //  std::cout << " the curr per=" << ans << std::endl;

  mySmartString = ans;

  return mySmartString;
}

void bullpgia::SmartGuesser::startNewGame(uint length)
{
   //   std::cout << " stat new game" << std::endl; //print

  this->length = length;
  pos = 0;
  perms.clear();
  digits.clear();
}
void bullpgia::SmartGuesser::learn(string reply)
{
  bool foundAllDigit = false;
  size_t i = reply.find(',');
  int b = stoi(reply.substr(0, i));
  int p = stoi(reply.substr(i + 1, reply.length()));
  //std::cout << " b=" << b << " p= " << p << std::endl;

  if ( digits.size() < length)
  {
  //  std::cout << "enter to add and the size :" <<digits.size()<< std::endl;

    for (size_t j = 0; j < b; j++)
    {
      digits.push_front(pos - 1);
    }
  //  std::cout << "the digit list:" << std::endl;

    for (auto v : digits)     ////// print
  //    std::cout << v << "\n"; ///// print

    if (digits.size() == length)
      foundAllDigit = true;
    else
    {
      return;
    }
  }
  if (foundAllDigit)
  {
      //    std::cout <<"in learn after found" << "\n"; ///// print

    string ans = "";
    for (std::list<int>::iterator it = digits.begin(); it != digits.end(); ++it)
    {
      char c = '0' + *it;
      ans += c;
    }
    char *chr = strdup(ans.c_str());

    findPermutations(chr, 0, length);
    free(chr);
    // std::cout << "the string list:" << std::endl;

   // for (auto v : perms)     ////// print
   //   std::cout << v << "\n"; ///// print
    foundAllDigit = false;
  }
}

///////////// this algoritim from this site https://www.geeksforgeeks.org/print-all-permutations-with-repetition-of-characters/

// Returns true if str[curr] does not matches with any of the
// characters after str[start]
bool bullpgia::SmartGuesser::shouldSwap(char str[], int start, int curr)
{
  for (int i = start; i < curr; i++)
    if (str[i] == str[curr])
      return 0;
  return 1;
}

// Prints all distinct permutations in str[0..n-1]
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

#ifndef WORD_H
#define WORD_H
#include <cstdlib>
#include <iostream>
#include <string>
#include "bag.h"
using namespace std;

class word
{
 public:
  word(){};
  word(string wordname, string filename);
  bag thisBag;
  string getWord();

 private:
  string myWord;

};
#endif

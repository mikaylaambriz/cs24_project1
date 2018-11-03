#include "word.h"

word::word(string wordname, string file)
{
  this->myWord=wordname;
  thisBag.add(file); 
}

string word::getWord(){
  return this->myWord;
}

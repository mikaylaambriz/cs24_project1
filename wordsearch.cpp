#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "word.h"

using namespace std;

/*function... might want it in some class?*/
int getdir (string dir, vector<string> &files)
{
  DIR *dp;
  struct dirent *dirp;
  if((dp  = opendir(dir.c_str())) == NULL) {
    cout << "Error(" << errno << ") opening " << dir << endl;
    return errno;
  }

  while ((dirp = readdir(dp)) != NULL) {
    files.push_back(string(dirp->d_name));
  }
  closedir(dp);
  return 0;
}


int main(int argc, char* argv[])
{
  string dir; //
  vector<string> files = vector<string>();

  if (argc < 2)
    {
      cout << "No Directory specified; Exiting ..." << endl;
      return(-1);
    }
  dir = string(argv[1]);
  if (getdir(dir,files)!=0)
    {
      cout << "Error opening " << dir << "; Exiting ..." << endl;
      return(-2);
    }
 
  word myArray[1000];
  bool found = false;
  int used = 0;

  string slash("/");
  for (unsigned int i = 0; i < files.size(); i++) {
    if(files[i][0]=='.')continue; //skip hidden files
    ifstream fin((string(argv[1])+slash+files[i]).c_str()); //open using absolute path
    // ...read the file...
    string myWord;
   while(true)
   {
     fin>>myWord;
     if(fin.eof()) {/*cout << "EOF " << files[i] << endl;*/ break;}
      else
      {
	//	cout<<files[i]<<"::"<<myWord<<endl;
	//If the array is empty
	if (used == 0)
	{
	  word wordObject(myWord,files[i]);
	  myArray[0] = wordObject;
	  used+=1;
	}
	else
	 {
	  for (int j=0; j<used; j++)
	   {
	    //If we find the word -> aka it's not unique
	    if (myArray[j].getWord()==myWord)
	     {
	      found = true;
	      //check if file is in bag
	      //if yes : increment count
	      myArray[j].thisBag.add(files[i]);
	      //if no : add file, count =1
	      //break
	     }
	    //If the word is unique -> aka we didn't find it in MyArray  
	   }

	  if(!found)
	  {
	    word wordObject(myWord,files[i]);
	    myArray[used] = wordObject;
	    //myArray[used].thisBag.print();
	    // make a new bag
	    // add file and set count = 1
	    used+=1;
	  }
	  found = false; 
	 }
      }
   }
   fin.close();
}
  /*  for (int i =0; i < used; i++) {
      cout<<myArray[i].getWord()<<endl;
      myArray[i].thisBag.print();
      }*/

  string search;
  while(search!="exit"){
   cout << "Enter word: ";
   cin >> search;
   cout << search << endl;
   
   for (int i=0; i < used; i++){
     if (myArray[i].getWord() == search){
       myArray[i].thisBag.print();
     }
   }
  }
}

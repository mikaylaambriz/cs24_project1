#include "bag.h"
bag::bag(){
    used = 0;
}

void bag::add(string fname){
    // check if fname already exists
    for (int i=0; i<used; i++) {
        if (file_names[i].filename()==fname) {
            // increment count
            file_names[i].set_count(file_names[i].count()+1);
            return;
        }
    }
    // exit from the loop ==> fname does not exist
    // insert the file name
    file_names[used].set_filename(fname);
    file_names[used].set_count(1);
    used = used + 1;
    return;
}

int bag::size() const{
  return used;
}

void bag::print() const{
    for (int i=0; i < used; i++) {
      cout << "File: " << file_names[i].filename() << "; Count: " << file_names[i].count() << endl;
    }
}

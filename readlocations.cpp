/*GARANCE NICOLE LOISON
 ID 10083186
 CPSC 441 - A3
 
 READLocationS.CPP
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
#include "readlocations.h"

using namespace std;

int main () {

    List LocationList;
    
    string line;
    ifstream myfile ("locations.txt");
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            
            char * cstr = new char [line.length()+1];
            strcpy (cstr, line.c_str());
            
            int len = line.length();
            char * p = strtok (cstr," ");
            LocationList.insert_first();
            LocationList.head->owner = p;
            LocationList.head->city=cstr[len-1];
          
            delete[] cstr;
        }
        myfile.close();
    }
    
    else cout << "Unable to open file locations.txt";
    LocationList.display();
    return 0;
}

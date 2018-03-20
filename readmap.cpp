/*GARANCE NICOLE LOISON
 ID 10083186
 CPSC 441 - A3
 
 READMAP.CPP
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
#include "readmap.h"

using namespace std;

/*main*/
int main () {

    List SegmentList;
    
    string line;
    ifstream myfile ("map.txt");
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            
            char * cstr = new char [line.length()+1];
            strcpy (cstr, line.c_str());
            
            int len = line.length();
            char * p = strtok (cstr," ");
            SegmentList.insert_first();
           
            while (p!=0)
            {
                int counter =0;
                while (counter<sizeof(cstr)){
                    SegmentList.head->city1=cstr[0];
                    SegmentList.head->city2=cstr[2];
                    SegmentList.head->distance= set_large(numerical_data(cstr,4));
                    SegmentList.head->time= set_large(numerical_data(cstr, 8));
                    SegmentList.head->gold = set_medium(numerical_data(cstr, 12));
                    SegmentList.head->trolls=set_small(atoi(&cstr[len-1]));
                    counter++;
                  
                }
                p = strtok(NULL," ");
               
            }
           
          
            delete[] cstr;
        }
        myfile.close();
    }
    
    else cout << "Unable to open file";
    SegmentList.display();
    return 0;
}

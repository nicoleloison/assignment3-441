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
#include "mapProcessing.h"

using namespace std;

/*main*/
int main () {
    Graph graph;
    Segment SegmentList;
    
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
           
            while (p!=0)
            {
                int counter =0;
                while (counter<sizeof(cstr)){
                    SegmentList.origin->name=cstr[0];
                    SegmentList.destination->name=cstr[2];
                    SegmentList.distance= set_large(numerical_data(cstr,4));
                    SegmentList.time= set_large(numerical_data(cstr, 8));
                    SegmentList.gold = set_medium(numerical_data(cstr, 12));
                    SegmentList.trolls=set_small(atoi(&cstr[len-1]));
                    counter++;
                  
                }
                SegmentList.origin->addSegment(SegmentList.destination,  SegmentList.distance, SegmentList.time, SegmentList.gold, SegmentList.trolls);
                graph.insert(SegmentList.origin);
                p = strtok(NULL," ");
               
            }
           
          
            delete[] cstr;
        }
        myfile.close();
    }
    
    else cout << "Unable to open file";
    graph.display();
    return 0;
}

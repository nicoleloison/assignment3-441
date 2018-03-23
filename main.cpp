/*GARANCE NICOLE LOISON
 ID 10083186
 CPSC 441 - A3
 
 main.cpp
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
#include "graph.h"

using namespace std;

/*main*/
int main (int argc, char* argv[]) {
    
    if (argc!=4)
    {
        cout <<" Please enter 3 arguments: map/fullmap hops/distance/time/trolls/gold addresses/fulladdresses"<<endl;
        return -1;
    }
    
    string filename, function, people;
    filename.assign(argv[1]);
    filename.append(".txt");
    function.assign(argv[2]);
    people.assign(argv[3]);
    people.append(".txt");
    
    cout << filename<<" "<<function<<" "<<people<<endl;


    
    string * a = get_address(people);
    string * c = get_city(a);
    int * algorithm = graph(filename, function, a);

    return 0;
}

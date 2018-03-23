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
#include "get_people.h"

using namespace std;

/*main*/
int main (int argc, char* argv[]) {
    
    if (argc!=3)
    {
        cout <<" Please enter 2 arguments: map/fullmap hops/hops/time/trolls/gold"<<endl;
        return -1;
    }
    
    string * n = get_people("contacts.txt");
    string * a = get_address("addresses.txt");
    string * c = get_city(a);
    
    string filename, function;
    filename.assign(argv[1]);
    filename.append(".txt");
    function.assign(argv[2]);
    cout << filename<<" "<<function<<endl;
    int * algorithm = graph(filename, function, a);

    return 0;
}

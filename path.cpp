/*GARANCE NICOLE LOISON
 ID 10083186
 CPSC 441 - A3
 
 PATH.CPP
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
int main () {
    
    string * n = get_people("contacts.txt");
    string * a = get_address("locations.txt");
    string * c = get_city(a);

    int * algorithm = graph("map.txt", "hops", a);

    return 0;
}

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

#include "readcontacts.h"
//#include "readmap.h"
#include "readlocations.h"
#include "graph.h"
#include "get_people.h"
#include "get_address.h"

using namespace std;

/*main*/
int main () {
    
    ListLocation locations= read_locations();
    ListHomes contacts =  read_contacts();
    string * n = get_people("contacts.txt");
    string * a = get_address("locations.txt");
    string * c = get_city(a);
    
    int * algorithm = graph("map.txt", "distance", a);
    
    /*
    for(int i = 0; i< le ; i++){
        cout << algorithm[i]<<
    }*/
    
    return 0;
}

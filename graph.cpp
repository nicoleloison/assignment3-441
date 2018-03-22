/*GARANCE NICOLE LOISON
 ID 10083186
 CPSC 441 - A3
 
 READMAP.CPP
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
#include <queue>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "graph.h"

#define INFINITY 65535

using namespace std;

int main (){
    int * algorithm;
    algorithm = graph("map.txt", "hops");
    return 0;
}


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
#include  <algorithm>
#include "readcontacts.h"
#include "readmap.h"
#include "readlocations.h"

using namespace std;
void shp();
void sdp();
void stp();
void ftp();

struct Graph
{
    List * list;
    int number;
    Graph();
    Graph(int v);
    void addEdge(Segment s);
    void display(void);
    
};
Graph::Graph(){}
Graph::Graph (int v){
    this->number=v;
    this->list = (struct List*) malloc(v * sizeof(struct List));
    // Initialize each adjacency list as empty by making head as NULL
    for (int i = 0; i < v; ++i){
        this->list[i].head = NULL;
    }
}
// Adds an edge to an undirected graph
void Graph::addEdge(Segment s){

}

void Graph::display(void){
}

/*
Shortest Hop Path (SHP): This algorithm finds the shortest path from source to destination, where the length of a path refers to the number of hops (i.e., links) traversed. Note that this algorithm ignores the physical distance, travel time, gold coins, and trolls for each link.*/
void shp(){
    
}

/*
Shortest Distance Path (SDP): This algorithm finds the shortest path from source to destination, where the length of a path refers to the cumulative total distance traveled. Note that this algorithm ignores the number of hops, travel time, as well as gold and trolls.*/

void sdp(){
    
}
/*
Shortest Time Path (STP): This algorithm finds the shortest path from source to destination, where the length of a path refers to the cumulative travel time for traversing the chosen links in the path. Note that this algorithm ignores the number of hops, as well as the distance (although distance and time are often correlated). Gold and trolls are also irrelevant.*/
void stp(){
    
}
/*
Fewest Trolls Path (FTP): This algorithm finds the path from source to destination that minimizes the number of trolls encountered. Note that this algorithm ignores the number of hops, as well as time, distance, and gold (although gold and trolls are often correlated).*/
void ftp(){
    
}


/*main*/
int main () {
    ListLocation locations= read_locations();
    List map =read_map();
    ListHomes contacts =  read_contacts();
   /*
    contacts.display();
    map.display();
    locations.display();*/
    return 0;
}

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
#include "path.h"

using namespace std;

class Vertex;

class Segment
{
public:
    Segment(Vertex *org, Vertex *dest, int dist)
    {
        origin = org;
        destination = dest;
        distance = dist;
    }
    
    Vertex* getOrigin() {return origin;}
    Vertex* getDestination() {return destination;}
    int getDistance() {return distance;}
private:
    Vertex* origin;
    Vertex* destination;
    int distance;
};


class Vertex
{
public:
    Vertex(string id)
    {
        name = id;
    }
    
    void addSegment(Vertex *v, int dist)
    {
        Segment newSegment(this, v, dist);
        Segments.push_back(newSegment);
    }
    
    void printSegments()
    {
        cout << name << ":" << endl;
        for (int i = 0; i < Segments.size(); i++)
        {
            Segment e = Segments[i];
            cout << e.getDestination()->getName() <<
            " - " << e.getDistance() << endl;
        }
        cout << endl;
    }
    
    string getName() {return name;}
    vector<Segment> getSegments() {return Segments;}
    
private:
    string name;
    vector<Segment> Segments;
};


class Graph
{
public:
    Graph() {}
    
    void insert(Vertex *v)
    {
        vertices.push_back(v);
    }
    
    void printGraph()
    {
        for (int i = 0; i < vertices.size(); i++)
            vertices[i]->printSegments();
    }
    
private:
    vector<Vertex*> vertices;
};

/*
Shortest Hop Path (SHP): This algorithm finds the shortest path from source to destination, where the length of a path refers to the number of hops (i.e., links) traversed. Note that this algorithm ignores the physical distance, travel time, gold coins, and trolls for each link.*/
void List::shp(){
    
}

/*
Shortest Distance Path (SDP): This algorithm finds the shortest path from source to destination, where the length of a path refers to the cumulative total distance traveled. Note that this algorithm ignores the number of hops, travel time, as well as gold and trolls.*/

void List::sdp(){
    
}
/*
Shortest Time Path (STP): This algorithm finds the shortest path from source to destination, where the length of a path refers to the cumulative travel time for traversing the chosen links in the path. Note that this algorithm ignores the number of hops, as well as the distance (although distance and time are often correlated). Gold and trolls are also irrelevant.*/
void List::stp(){
    
}
/*
Fewest Trolls Path (FTP): This algorithm finds the path from source to destination that minimizes the number of trolls encountered. Note that this algorithm ignores the number of hops, as well as time, distance, and gold (although gold and trolls are often correlated).*/
void List::ftp(){
    
}


/*main*/
int main () {
    
    return 0;
}

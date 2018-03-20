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

using namespace std;

int set_large( int len );
int set_medium (int g);
int set_small (int t);
int numerical_data(char* ch, int start);
struct City;

/*Segment = Edge of Graph*/
struct Segment
{
    City* origin;
    City* destination;
    int distance, time, gold, trolls;
    Segment();
    Segment(City *org, City *to, int dist, int ti, int g, int t);
};
Segment::Segment(void){
    /*empty constructor*/
}
Segment::Segment(City *org, City *to, int dist, int ti, int g, int t){
    origin =org;
    destination = to;
    distance = dist;
    time = ti;
    gold =g;
    trolls = t;
}


/*City = Vertex of Graph*/
struct City
{
    char name;
    int id;
    vector<Segment> segments;
    City();
    City(char c);
    void addSegment(City *v, int dist, int ti, int g, int t);
    void printSegments();

};
City::City(void){};
City::City(char c){
    name=c;
};

void City::addSegment(City *v, int dist, int ti, int g, int t)
{
    Segment newSegment(this, v, dist, ti, g, t);
    this->segments.push_back(newSegment);
}

void City::printSegments()
{
    cout << name << ":" << endl;
    for (int i = 0; i < segments.size(); i++)
    {
        Segment e = segments[i];
        cout << e.destination->name <<
        " distance: " << e.distance <<
        " time: " << e.time <<
        " gold: " << e.gold <<
        " trolls: " << e.distance << endl;
    }
    cout << endl;
}


struct Graph
{    Graph() {}
    vector<City*> cities;
    int number;
    
    void display();
    void insert(City *c);
    
};

void Graph::insert(City *v)
{
    this->cities.push_back(v);
    number++;
}
void Graph::display()
{
    for (int i = 0; i < cities.size(); i++)
        cities[i]->printSegments();
}

/*helper*/
int set_large(int len) {
    if (len< 0 || len > 1000){
        cout << "Invalid Distance. 0<= Value <=1000 " << endl;
        return -1;
    }
    else{
        return len;
    }
}

int set_medium( int g ) {
    if (g< 0 || g > 100){
        cout << "Invalid Gold. 0<=Gold<=100 " << endl;
         return -1;
    }
    else{
         return g;
    }
}


int set_small( int t ) {
    if (t< 0 || t > 10){
        cout << "Invalid Trolls number. 0<=trols<=10 " << endl;
         return -1;
    }
    else{
         return t;
    }
}

int numerical_data(char* ch, int start){
    char l[4]= {'\0'};
    for (int a =0; a<3;a++){
        l[a]=ch [start+a];
    }
    return atoi(l);
}

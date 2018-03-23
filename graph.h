/*GARANCE NICOLE LOISON
 ID 10083186
 CPSC 441 - A3
 
 graph.h
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

#include "get_address.h"

#define INFINITY 65535

using namespace std;
const int LEVELS = 27;
const int source_city= 'C'-65;//Calgary , C=2;

struct nodeVariable
{
    int node;
    int variable;
    int time, distance, trolls, hops, gold;
};

class CompareVariable
{
public:
    bool operator()(nodeVariable& n1, nodeVariable& n2)
    {
        if (n1.variable > n2.variable)
            return true;
        else
            return false;
    }
};

int ** assign_variable(string v, int ** hops, int **distance, int **time,  int **gold, int **trolls){
    
    if (v.compare("distance")==0) {
        return distance;
    }
    else if (v.compare("time")==0){
        return time;
    }
    else if (v.compare("hops")==0) {
        return hops;
    }
    else if (v.compare("trolls")==0){
        return trolls;
    }
    else if (v.compare("gold")){
        return gold;
    }
    
    //default hops
    else
        return hops;
}


int * dijkstra(string v, int ** hops, int **distance, int **time, int **gold,  int **trolls, string* addresses)
{
    
    int ** graph = assign_variable(v, hops, distance, time, gold ,trolls);
    int * results;
    int mini;
    bool *visited = new bool [LEVELS];
    
    int *vr = new int [LEVELS];
    
    int *h = new int [LEVELS];
    int *r = new int [LEVELS];
    int *d = new int [LEVELS];
    int *g = new int [LEVELS];
    int *t = new int [LEVELS];
    
    
    
    // Start with variable value of each node as infinity and visited status as false
    for (int i = 0; i < LEVELS; i++)
    {
        vr[i] = INFINITY;
        
        h[i]=0;
        d[i]=0;
        t[i]=0;
        g[i]=0;
        r[i]=0;
        
        visited[i] = false;
    }
    
    // the distance of the source to itself is 0
    vr[source_city] = 0;
    t[source_city] = 0;
    h[source_city] = 0;
    d[source_city] = 0;
    r[source_city] = 0;
    g[source_city] = 0;
    
    // instantiate a priority queue with the structure and comparison criteria
    // as defined above
    priority_queue< nodeVariable, vector< nodeVariable >, CompareVariable> pq;
    
    // First node as the source and put it into the queue
    nodeVariable first = {source_city,0, 0, 0, 0, 0};
    pq.push(first);
    
    // While queue is not empty, pick the topmost node
    // using it's neighbors update the distance of each node that can be reached
    // and insert that node in the priority queue
    while(!pq.empty())
    {
        nodeVariable temp = pq.top();
        pq.pop();
        int node= temp.node;
        for(int i=0;i < LEVELS;i ++ )
        {
            if(graph[node][i]!=0)
            {
                // Update the variable if it is smaller than the current distance
                if(vr[i] > (vr[node]+graph[node][i])){
                    vr[i] = vr[node]+graph[node][i];
                    
                    h[i] = h[node]+hops[node][i];
                    d[i] = d[node]+distance[node][i];
                    t[i] = t[node]+time[node][i];
                    g[i] = g[node]+gold[node][i];
                    r[i] = r[node]+trolls[node][i];
                    
                }
                
                
                // If not visited put it into the queue
                if(!visited[i])
                {
                    nodeVariable newNode;
                    newNode.node=i;
                    newNode.variable=vr[i];
                    newNode.hops = h[i];
                    newNode.distance = d[i];
                    newNode.time=t[i];
                    newNode.trolls = r[i];
                    newNode.gold = g[i];
                    
                    pq.push(newNode);
                    visited[i]=true;
                }
            }
        }
        
    }
    
    if (v.compare("distance")==0) {
        d = vr;
    }
    else if (v.compare("time")==0){
        t = vr;
    }
    else if (v.compare("hops")==0) {
        h = vr;
    }
    else if (v.compare("trolls")==0){
        r = vr;
    }
    
    cout << "\nThe minimum "<< v <<" from " << char (source_city+65) << " for the dwarves are:"<<endl;
    cout<< flush;
    
    for(int i=0;i < LEVELS;i++)
    {
        int letter = i + 65;
        char ccc =  (char) letter;
        string d = get_dwarf_from_city(addresses,ccc);
        
        if (vr[i] != INFINITY && i != source_city)//remove node unvisited + src
        {
            results[i]= vr[i];
           
            string dw;
            dw.assign(d);
    
            cout << d << " can go from "<< ccc << " to destination:\n"
            <<"going through\t"<<h[i]<<" hops "
            <<"travelling\t"<<d[i]<<" km "
            <<"for\t" <<t[i]<<" hours "
            <<"collecting\t"<<g[i]<<" pieces of gold"
            <<"encountering\t"<<r[i]<<" trolls." << flush <<endl;
            cout << endl;
        }
    }
    
    delete [] t;
    delete [] d;
    delete [] h;
    delete [] g;
    delete [] r;

    return results;
    
}


/*distance*/
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

int** create2DArray()
{
    int** array2D = 0;
    array2D = new int*[27];
    
    for (int h = 0; h < 27; h++)
    {
        array2D[h] = new int[27];
        
        for (int w = 0; w < 27; w++)
        {
            array2D[h][w] = 0;
        }
    }
    
    return array2D;
}

void populate(int** a, int i , int j, int variable){
    if (a[i][j]==0){
        a[i][j] = variable;
        a[j][i] = variable;
    }
}
void show (int ** array2D){
    int l = 27;
    for (int h = 0; h < l; h++){
        for (int w = 0; w < l; w++){
            if (array2D[h][w]!=0){
                char src = char(65 + h);
                char dest = char (65 + w);
                cout <<src<<" - "<<dest<<": "<< array2D[h][w]<<endl;
            }
        }
    }
}

void display(int ** array2D){
    
    for (int h = 0; h < LEVELS; h++)
    {
        for (int w = 0; w < LEVELS; w++)
        {
            cout << array2D[h][w]  << "  ";
        }
        cout << endl;
    }
}

void show_stats( int * calculated){
    
}

void clean(int ** c){
    delete * c;
    delete  c;
    c = NULL;
}

/* RETURNS  int * graph(string filename, string variable)*/

int * graph(string filename, string variable, string* addresses)
{
    //string variable_distance = "distance";
    string line;
    ifstream file (filename);
    int line_count = 0;
    
    int** c_h = create2DArray();
    int** c_d = create2DArray();
    int** c_t = create2DArray();
    int** c_g = create2DArray();
    int** c_r = create2DArray();
    
    if (file.is_open()){
        
        while ( getline (file,line) )
        {
            line_count++;
            char * cstr = new char [line.length()+1];
            strcpy (cstr, line.c_str());
            
            char * p = strtok (cstr," ");
            int src, dest, distance, time, gold, hops, trolls;
            
            src =cstr[0]-'A';
            dest = cstr[2]-'A';
            
            int hop=1;//hops are always 1 from city to city;
            distance = set_large(numerical_data(cstr,4));
          //  cout<<"distance: "<<distance<<endl;
            time =set_large(numerical_data(cstr, 8));
            gold = set_medium(numerical_data(cstr, 12));
            trolls =  set_small(atoi(&cstr[line.length()-1]));
            
            populate(c_h, src , dest, hop);
            populate(c_d, src, dest, distance);
            populate(c_t, src , dest, time );
            populate(c_g, src , dest, gold);
            populate(c_r, src , dest, trolls);
            
            
            delete[] cstr;
            
        }
        file.close();
    }
    
    else cout << "Unable to open file";
        
        int * weights;
        weights = dijkstra(variable, c_h, c_d, c_t, c_g, c_r, addresses);
        
        clean(c_h);
        clean(c_d);
        clean(c_t);
        clean(c_g);
        clean(c_r);
    
        return weights ;
        
}

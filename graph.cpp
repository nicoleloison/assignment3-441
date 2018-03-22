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

#define INFINITY 65535

using namespace std;
const int LEVELS = 27;
const int source_city= 'C'-65;//Calgary , C=2;

struct nodeVariable
{
    int node;
    int variable;
    int time, distance, gold, trolls, hops;
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

int * dijkstra(string v, int **graph)
{
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
        t[i]=0;
        d[i]=0;
        r[i]=0;
        g[i]=0;
        h[i]=0;
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
                // Update the distance if it is smaller than the current distance
                if(vr[i] > (vr[node]+graph[node][i])){
                    vr[i] = vr[node]+graph[node][i];
                    t[i] = t[node]+graph[node][i];
                    h[i] = h[node]+graph[node][i];
                    g[i] = g[node]+graph[node][i];
                    d[i] = d[node]+graph[node][i];
                    r[i] = r[node]+graph[node][i];
                    
                }
                
                
                // If not visited put it into the queue
                if(!visited[i])
                {
                    nodeVariable newNode;
                    newNode.node=i;
                    newNode.variable=vr[i];
                    newNode.time=t[i];
                    newNode.distance = d[i];
                    newNode.trolls = r[i];
                    newNode.gold = g[i];
                    newNode.hops = h[i];
                    pq.push(newNode);
                    visited[i]=true;
                }
            }
        }
        
    }
    
    if (v.compare("distance")) {
        d = vr;
    }
    else if (v.compare("time")){
        t = vr;
    }
    else if (v.compare("hops")) {
        h = vr;
    }
    else if (v.compare("trolls")){
        r = vr;
    }
    
    cout << "The minimum "<< v <<" from " << char (source_city+65) << " to all the nodes is" << endl;
  
    for(int i=0;i < LEVELS;i++)
    {
        int letter = i + 65;
        if (vr[i] != INFINITY && i != source_city)//remove node unvisited + src
        {
            results[i]= vr[i];
            //cout << c <<endl;
          //  cout <<  (char)letter<< " : " << results[i] <<" aside time: "<< t[i]<< "\n";
            cout <<"From "<<(char)letter<< " number of hops: "<< h[i]<<" distance:" << d[i] <<" time:" <<t[i]<<" gold:"<<g[i]<<" trolls:"<<r[i] <<"\n";
        }
    }
    cout<< endl<<endl;//do not remove or bus fault.
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


/* RETURNS  string * graph(string filename, string variable)*/

int main()
{
    string variable_distance = "distance";
    string line;
    ifstream file ("map.txt");
    int line_count = 0;
    int** c_d = create2DArray();
  //  int** c_g = create2DArray();
    int** c_t = create2DArray();
    int** c_h = create2DArray();
    int** c_tr = create2DArray();
    
  //  ifstream file (myfile);
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
            
            distance = set_large(numerical_data(cstr,4));
            time =set_large(numerical_data(cstr, 8));
            //gold = set_medium(numerical_data(cstr, 12));
            trolls =  set_small(atoi(&cstr[line.length()-1]));
            int h=1;//hops are always 1 from city to city;
           
            
            populate(c_d, src, dest, distance);
            populate(c_t, src , dest, time );
            //populate(c_g, src , dest, );
            populate(c_tr, src , dest, trolls);
            populate(c_h, src , dest, h);
            
            delete[] cstr;
            
        }
        file.close();
    }
    
    else cout << "Unable to open file";
        
        int * weights;
    /*
    string * results;
    results->assign("To Calgary, minimizing variable the path are:\n");
    results->append("From: city name, Number of hops: hops , total distance: dist, total time: t, Gold collected: g, trolls encountered: t");
    cout << results<< endl;*/
        // display(c_d);
        //show(c_d);

       // cout<< "min distance: "<< endl;
        weights = dijkstra("distance", c_d);
        //cout<< "min time: "<< endl;
        weights= dijkstra("time", c_t);
       // cout<< "min trolls: "<< endl;
        weights= dijkstra("trolls", c_tr);
       // cout<< "min hops: "<< endl;
        weights= dijkstra("hops", c_h);
    
    
        
        delete * c_d;
        delete  c_d;
        c_d = NULL;
        
        return 0;
        }


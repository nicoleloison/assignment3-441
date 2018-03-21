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

struct nodeDistance
{
    int node;
    int distance;
};

class CompareDist
{
public:
    bool operator()(nodeDistance& n1, nodeDistance& n2)
    {
        if (n1.distance > n2.distance)
            return true;
        else
            return false;
    }
};

void dijkstra(int s, int size, int **graph)
{
    int mini;
    bool *visited = new bool [size];
    unsigned int *dist = new unsigned int [size];
    
    // initialize the dist of each node as infinity and visited status as false
    for (int i = 0; i < size; i++)
    {
        dist[i] = INFINITY;
        visited[i] = false;
    }
    
    // the distance of the source to itself is 0
    dist[s] = 0;
    
    // instantiate a priority queue with the structure and comparison criteria
    // as defined above
    priority_queue< nodeDistance, vector< nodeDistance >, CompareDist> pq;
    
    // Create the first node as the source and put it into the queue
    nodeDistance first = {s,0};
    pq.push(first);
    
    // While queue is not empty, pick the topmost node
    // using it's neighbors update the distance of each node that can be reached
    // and insert that node in the priority queue
    while(!pq.empty())
    {
        nodeDistance temp = pq.top();
        pq.pop();
        int node= temp.node;
        for(int i=0;i < size;i ++ )
        {
            if(graph[node][i]!=0)
            {
                // Update the distance if it is smaller than the current distance
                if(dist[i] > (dist[node]+graph[node][i]))
                    dist[i] =dist[node]+graph[node][i];
                
                // If not visited put it into the queue
                if(!visited[i])
                {
                    nodeDistance newNode;
                    newNode.node=i;
                    newNode.distance=dist[i];
                    pq.push(newNode);
                    visited[i]=true;
                }
            }
        }
        
    }
    
    cout << "The shortest distance from " << char (67) << " to all the nodes is" << endl;
    for(int i=0;i < size;i++)
    {
        int letter = i + 65;
        if (dist[i] != INFINITY)
        cout <<  (char)letter<< " : " << dist[i] << endl;
    }
    cout << endl << endl;
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

void populate(int** a, int i , int j, int distance){
    if (a[i][j]==0){
        a[i][j] = distance;
        a[j][i] = distance;
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


/* RETURNS LIST SEGM*/
int main()
{
    
    string line;
    ifstream myfile ("map.txt");
    int LEVELS = 27;
    int** c_d = create2DArray();

    ifstream file ("map.txt");
    if (file.is_open()){
        
        while ( getline (file,line) )
        {
            char * cstr = new char [line.length()+1];
            strcpy (cstr, line.c_str());
            
            char * p = strtok (cstr," ");
            int src, dest, distance;
            
            src =cstr[0]-'A';
            dest = cstr[2]-'A';
            distance = set_large(numerical_data(cstr,4));
          //  cout <<" src : "<< cstr[0]<<" to "<<"dest : "<< cstr[2]<< endl;
            populate(c_d, src, dest, distance);
            
            delete[] cstr;
        
        }
        file.close();
    }
  
    else cout << "Unable to open file";
    
    
    
    display(c_d);
    show(c_d);
    int s = 2;
    
    dijkstra(s, LEVELS, c_d);
    
    
    delete * c_d;
    delete  c_d;
    c_d = NULL;
   
    return 0;
}

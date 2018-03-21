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
#include <stdio.h>
#include <stdbool.h>

using namespace std;


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

// Structure of a vertex
struct vertex {
    char city_name;//city
    struct node *list;
    struct vertex *next;
};
typedef struct vertex * VPTR;

// Struct of adjacency list
struct node {
    int weight;
    struct vertex * n;
    struct node *next;
};
typedef struct node * NODEPTR;

class Graph {
public:
    // list of nodes chained together
    VPTR V;
    Graph() {
        V = NULL;
    }
    void addEdge(char, char, int);
    VPTR addVertex(char);
    VPTR existVertex(char i);
    void listVertex();
    void listEdges();
};

// If vertex exist, it returns its pointer else returns NULL
VPTR Graph::existVertex(char i) {
    VPTR temp  = V;
    while(temp != NULL) {
        if(temp->city_name == i) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}
// Add a new vertex to the end of the vertex list
VPTR Graph::addVertex(char i) {
    VPTR temp = new(struct vertex);
    temp->list = NULL;
    temp->city_name = i;
    temp->next = NULL;
    
    VPTR *curr = &V;
    while(*curr) {
        curr = &(*curr)->next;
    }
    *curr = temp;
    return temp;
}

// Add a node from vertex i to j.
// first check if i and j exists. If not first add the vertex
// and then add entry of j into adjacency list of i with the weights

void Graph::addEdge(char i, char j, int w) {
    
    VPTR v_i = existVertex(i);
    VPTR v_j = existVertex(j);
    if(v_i == NULL) {
        v_i = addVertex(i);
    }
    if(v_j == NULL) {
        v_j = addVertex(j);
    }
    
    NODEPTR *temp = &(v_i->list);
    while(*temp) {
        temp = &(*temp)->next;
    }
    *temp = new(struct node);
    (*temp)->weight= w;
    (*temp)->n = v_j;
    (*temp)->next = NULL;
}
//List all the vertex. and their weight
void Graph::listVertex() {
    VPTR temp = V;
    while(temp!=NULL) {
        cout <<temp->city_name <<" -> ";
        temp = temp->next;
    }
    cout <<"\n";
    
}

//List all the vertex. and their weight
void Graph::listEdges() {
    VPTR tempV = V;
    NODEPTR * temp = &(tempV->list);
    while(*temp!=NULL) {
        cout <<&(*temp)->n->city_name<< " has weight " << (*temp)->weight<<" with "<< &(*temp)->n->next->city_name << endl;
        temp = &(*temp)->next;
    }

    cout <<"\n";
    
}


/* RETURNS LIST SEGM*/
int main()
{
    Graph G;
    
    string line;
    ifstream myfile ("map.txt");
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            
            char * cstr = new char [line.length()+1];
            strcpy (cstr, line.c_str());
            
            int len = line.length();
            char * p = strtok (cstr," ");
            
            while (p!=0)
            {
                vertex * new_city = G.existVertex(cstr[0]);
                if (new_city == nullptr){
                    G.addVertex(cstr[0]);
                    //adding weight of distance for now ???
                    G.addEdge(cstr[0], cstr[2], set_large(numerical_data(cstr,4)));
                              
                              }
                              else{
                     G.addEdge(cstr[2], cstr[1], set_large(numerical_data(cstr,4)));
                               }
                
               
                /*
                int counter =0;
                while (counter<sizeof(cstr)){
                    
                     G.addEdge();
                    SegmentList.head->city1=cstr[0];
                    SegmentList.head->city2=cstr[2];
                    SegmentList.head->distance= set_large(numerical_data(cstr,4));
                    SegmentList.head->time= set_large(numerical_data(cstr, 8));
                    SegmentList.head->gold = set_medium(numerical_data(cstr, 12));
                    SegmentList.head->trolls=set_small(atoi(&cstr[len-1]));
                    counter++;
                 }*/
                p = strtok(NULL," ");
                
            }
            
            
            delete[] cstr;
            delete p;
        }
        myfile.close();
    }
  
    else cout << "Unable to open file";
    
    G.listVertex();
    G.listEdges();
    return 0;
}

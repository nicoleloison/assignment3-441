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

int set_large( int len );
int set_medium (int g);
int set_small (int t);
int numerical_data(char* ch, int start);
class List;
struct Segment;
struct City;
struct Edge;
List filter(string filter, List * list);
List find_path( List * a, List * b);
bool connected (Segment * a, Segment * b, List *l);
List read_map();

struct City {
    typedef pair<int, City*> ve;
    vector<ve> adj; //cost of edge, destination vertex
    string city;
    City(string s) : city(s) {}
};


class Graph
{
public:
    typedef map<string, vertex *> vmap;
    vmap work;
    void addcity(const string&);
    void addedge(const string& from, const string& to, double cost);
};

void Graph::addcity(const string &city)
{
    vmap::iterator itr = work.find(city);
    if (itr == work.end())
    {
        City *v;
        v = new City(city);
        work[city] = v;
        return;
    }
    cout << "\nVertex already exists!";
}

void graph::addedge(const string& from, const string& to, double cost)
{
    City *f = (work.find(from)->second);
    City *t = (work.find(to)->second);
    pair<int, City *> edge = make_pair(cost, t);
    f->adj.push_back(edge);
}

class graph
{
public:
    typedef map<string, City *> vmap;
    vmap work;
    void addcity(const string&);
    void addedge(const string& from, const string& to, double cost);
};


void graph::addvertex(const string &name)
{
    vmap::iterator itr = work.find(name);
    if (itr == work.end())
    {
        vertex *v;
        v = new vertex(name);
        work[name] = v;
        return;
    }
    cout << "\nVertex already exists!";
}

void graph::addedge(const string& from, const string& to, double cost)
{
    vertex *f = (work.find(from)->second);
    vertex *t = (work.find(to)->second);
    pair<int, vertex *> edge = make_pair(cost, t);
    f->adj.push_back(edge);
}


/***Segment Object**/
struct Segment {
    string city1, city2;
    int distance, time, gold, trolls, id;
    
    Segment();
    Segment(string c1, string c2, int d, int ti, int g, int tr);
    Segment * next;
    
};
Segment::Segment(void){
    /*empty constructor*/
}

Segment::Segment(string c1, string c2, int d, int ti, int g, int tr){
    city1=c1;
    city2=c2;
    distance=d;
    time=ti;
    gold=g;
    trolls=tr;
    id =0;
    next=NULL;
}


/*Linked List of Segments */
struct List
{
    int number_of_seg;
    Segment * head, * tail;
    List()
    {
        head=NULL;
        tail=NULL;
        number_of_seg=0;
    }
    void display();
    void append(Segment ** head_ref, Segment s);
    void insert_first();
};

void List::append(Segment ** head_ref, Segment s)
{
    number_of_seg++;
    /* 2. allocate new node */
    Segment *new_node= (struct Segment*) malloc(sizeof(struct Segment));
    Segment *last = *head_ref;
    
    new_node->city1=s.city1;
    new_node->city2=s.city2;
    new_node->distance=s.distance;
    new_node->gold=s.gold;
    new_node->time=s.time;
    new_node->trolls=s.trolls;
    new_node->id = number_of_seg;
    
    new_node->next = NULL;
    
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    return;
    
    
}

void List::insert_first()
{
    number_of_seg++;
    Segment *temp=new Segment;
    
    temp->city1='\0';
    temp->city2='\0';
    temp->distance=0;
    temp->time=0;
    temp->gold=0;
    temp->trolls=0;
    temp->id=number_of_seg;
    temp->next=head;
    head=temp;
}

/*display node*/

void List::display()
{
    Segment *temp=new Segment;
    temp=head;
    while(temp!=NULL)
    {
        cout<<" "<< temp->city1 << " - "<< temp->city2 << " ,distance: "<< temp->distance << " time: "<< temp->time << " gold: "<< temp->gold << " trolls: "<< temp->trolls<< endl;
        temp=temp->next;
    }
    delete temp;
    temp=NULL;
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
/*filters the list with only the ones having the city*/
List filter(string filter, List *list){
   
    List result;
    Segment *temp=new Segment;
    temp=list->head;
    string str[6];
    
    while(temp!=NULL)
    {
  
        str[0].assign(temp->city1);
        str[1].assign(temp->city2);
        str[2].assign(to_string(temp->distance));
        str[3].assign(to_string(temp->time));
        str[4].assign(to_string(temp->gold));
        str[5].assign(to_string(temp->trolls));
        
        
        if (str[0].compare(filter)==0||str[1].compare(filter)==0 ){
            //Segment sa = Segment(str[0], str[1], atoi(str[2].c_str()),  atoi(str[3].c_str()),  atoi(str[4].c_str()),  atoi(str[5].c_str()));
            //cout <<"filtered: " <<str[0]<< " - "<<str[1]<<" with dist "<< str[2]<<endl;
            result.append(&result.head, * temp);
        }
        
      temp=temp->next;
    }
    delete temp;
    temp=NULL;
    
    for (int j = 0; j<6;j++){
        str[j].clear();
    }
    return result;
}

List find_path(List * a, List *b){
    List common;
    Segment *t1=new Segment;
    t1=a->head;
    int counter =0;
    string str1[6];
    string str2[6];
    
    while(t1!=NULL && counter <10)
    {
        counter++;
        
        str1[0].assign(t1->city1);
        str1[1].assign(t1->city2);
        str1[2].assign(to_string(t1->distance));
        str1[3].assign(to_string(t1->time));
        str1[4].assign(to_string(t1->gold));
        str1[5].assign(to_string(t1->trolls));

        Segment *t2=new Segment;
        t2=b->head;
        int ctr = 0;

        while (t2!=NULL && ctr<5) {
            ctr ++;
            
            str2[0].assign(t2->city1);
            str2[1].assign(t2->city2);
            str2[2].assign(to_string(t2->distance));
            str2[3].assign(to_string(t2->time));
            str2[4].assign(to_string(t2->gold));
            str2[5].assign(to_string(t2->trolls));
        
            
            if (str1[0].compare(str2[0])==0)
            {
                //ex
                //in a winnipeg: w - t
                //in b yyc:  w - c
                Segment sa = Segment(str1[1], str1[0], atoi(str1[2].c_str()),  atoi(str1[3].c_str()),  atoi(str1[4].c_str()),  atoi(str1[5].c_str()));
                Segment sb = Segment(str2[0], str2[1], atoi(str2[2].c_str()),  atoi(str2[3].c_str()),  atoi(str2[4].c_str()),  atoi(str2[5].c_str()));
                common.append( &common.head, sa);
                common.append( &common.head, sb);
                common.number_of_seg--;
                break;
                //t - w , w - c ???
               
            }
            else if(str1[0].compare(str2[1])==0) {
                       cout<<"yass 2 "<<endl;/*
                //always srtarting from a so ... no ?
                //ex
                //in winnipeg: w - t
                //in yyc:  c - w
                Segment sa = new Segment(str1[1], str1[0], atoi(str1[2].c_str()),  atoi(str1[3].c_str()),  atoi(str1[4].c_str()),  atoi(str1[5].c_str()));
                Segment sb = new Segment(str2[1], str2[0], atoi(str2[2].c_str()),  atoi(str2[3].c_str()),  atoi(str2[4].c_str()),  atoi(str2[5].c_str()));
                common.insert(sb);
                common insert(sa);
                //t - w , w -c*/
            }
            else if(str1[1].compare(str2[0])==0) {
                //ex
                //in winnipeg: w - c
                //in yyc:  c - t
                Segment sa = Segment(str1[0], str1[1], atoi(str1[2].c_str()),  atoi(str1[3].c_str()),  atoi(str1[4].c_str()),  atoi(str1[5].c_str()));
                Segment sb = Segment(str2[0], str2[1], atoi(str2[2].c_str()),  atoi(str2[3].c_str()),  atoi(str2[4].c_str()),  atoi(str2[5].c_str()));
                common.append( &common.head, sa);
                common.append( &common.head, sb);
                common.number_of_seg--;
                break;
                //w -c , c - t
            }
            
            else if(str1[1].compare(str2[1])==0){
               // cout <<"adding format  //w -c , c - t " << endl;
                //ex
                //in winnipeg: w - t
                //in yyc:  c - t
                
                Segment sa = Segment(str1[0], str1[1], atoi(str1[2].c_str()),  atoi(str1[3].c_str()),  atoi(str1[4].c_str()),  atoi(str1[5].c_str()));
                Segment sb = Segment(str2[1], str2[2], atoi(str2[2].c_str()),  atoi(str2[3].c_str()),  atoi(str2[4].c_str()),  atoi(str2[5].c_str()));
                common.append(&common.head, sa);
                common.append( &common.head, sb);
                common.number_of_seg--;
                break;
                // w - t ,t -c
            }
            t2=t2->next;
        }
        
        for (int j = 0; j<6;j++){
            str2[j].clear();
        }
        
        t1= t1->next;
    }
    
    delete t1;
    t1=NULL;
    
    for (int j = 0; j<6;j++){
        str1[j].clear();
    }
    cout<<"Path took "<<common.number_of_seg<<" hops from "<<a->head->city1<<endl;
    return common;
}

bool connected (Segment * a, Segment * b, List *l){
    List common;
    Segment *t1=new Segment;
    t1=l->head;
    int counter =0;
    string str1[6];
    string str2[6];
    
    while(t1!=NULL && counter <10)
    {
        counter++;
        
        str1[0].assign(t1->city1);
        str1[1].assign(t1->city2);
        str1[2].assign(to_string(t1->distance));
        str1[3].assign(to_string(t1->time));
        str1[4].assign(to_string(t1->gold));
        str1[5].assign(to_string(t1->trolls));
        
        Segment *t2=new Segment;
        t2=b->head;
        int ctr = 0;
        
        while (t2!=NULL && ctr<5) {
            ctr ++;
            
            str2[0].assign(t2->city1);
            str2[1].assign(t2->city2);
            str2[2].assign(to_string(t2->distance));
            str2[3].assign(to_string(t2->time));
            str2[4].assign(to_string(t2->gold));
            str2[5].assign(to_string(t2->trolls));
            
            
            if (str1[0].compare(str2[0])==0)
            {
                //ex
                //in a winnipeg: w - t
                //in b yyc:  w - c
                Segment sa = Segment(str1[1], str1[0], atoi(str1[2].c_str()),  atoi(str1[3].c_str()),  atoi(str1[4].c_str()),  atoi(str1[5].c_str()));
                Segment sb = Segment(str2[0], str2[1], atoi(str2[2].c_str()),  atoi(str2[3].c_str()),  atoi(str2[4].c_str()),  atoi(str2[5].c_str()));
                common.append( &common.head, sa);
                common.append( &common.head, sb);
                common.number_of_seg--;
                break;
                //t - w , w - c ???
                
            }
            else if(str1[0].compare(str2[1])==0) {
                cout<<"yass 2 "<<endl;/*
                                       //always srtarting from a so ... no ?
                                       //ex
                                       //in winnipeg: w - t
                                       //in yyc:  c - w
                                       Segment sa = new Segment(str1[1], str1[0], atoi(str1[2].c_str()),  atoi(str1[3].c_str()),  atoi(str1[4].c_str()),  atoi(str1[5].c_str()));
                                       Segment sb = new Segment(str2[1], str2[0], atoi(str2[2].c_str()),  atoi(str2[3].c_str()),  atoi(str2[4].c_str()),  atoi(str2[5].c_str()));
                                       common.insert(sb);
                                       common insert(sa);
                                       //t - w , w -c*/
            }
            else if(str1[1].compare(str2[0])==0) {
                //ex
                //in winnipeg: w - c
                //in yyc:  c - t
                //  cout <<"adding format  //w -c , c - t " << endl;
                Segment sa = Segment(str1[0], str1[1], atoi(str1[2].c_str()),  atoi(str1[3].c_str()),  atoi(str1[4].c_str()),  atoi(str1[5].c_str()));
                Segment sb = Segment(str2[0], str2[1], atoi(str2[2].c_str()),  atoi(str2[3].c_str()),  atoi(str2[4].c_str()),  atoi(str2[5].c_str()));
                common.append( &common.head, sa);
                common.append( &common.head, sb);
                common.number_of_seg--;
                break;
                //w -c , c - t
            }
            
            else if(str1[1].compare(str2[1])==0){
                // cout <<"adding format  //w -c , c - t " << endl;
                //ex
                //in winnipeg: w - t
                //in yyc:  c - t
                
                Segment sa = Segment(str1[0], str1[1], atoi(str1[2].c_str()),  atoi(str1[3].c_str()),  atoi(str1[4].c_str()),  atoi(str1[5].c_str()));
                Segment sb = Segment(str2[1], str2[2], atoi(str2[2].c_str()),  atoi(str2[3].c_str()),  atoi(str2[4].c_str()),  atoi(str2[5].c_str()));
                common.append(&common.head, sa);
                common.append( &common.head, sb);
                common.number_of_seg--;
                break;
                // w - t ,t -c
            }
            t2=t2->next;
        }
        
        for (int j = 0; j<6;j++){
            str2[j].clear();
        }
        
        t1= t1->next;
    }
    
    delete t1;
    t1=NULL;
    
    for (int j = 0; j<6;j++){
        str1[j].clear();
    }
    cout<<"Path took "<<common.number_of_seg<<" hops from "<<a->head->city1<<endl;
    return common;
    return false;
}

/* RETURNS LIST SEGM*/
List read_map()
{
    List SegmentList;
    
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
            SegmentList.insert_first();
            
            while (p!=0)
            {
                int counter =0;
                while (counter<sizeof(cstr)){
                    SegmentList.head->city1=cstr[0];
                    SegmentList.head->city2=cstr[2];
                    SegmentList.head->distance= set_large(numerical_data(cstr,4));
                    SegmentList.head->time= set_large(numerical_data(cstr, 8));
                    SegmentList.head->gold = set_medium(numerical_data(cstr, 12));
                    SegmentList.head->trolls=set_small(atoi(&cstr[len-1]));
                    counter++;
                    
                }
                p = strtok(NULL," ");
                
            }
            
            
            delete[] cstr;
            delete p;
        }
        myfile.close();
    }
    
    else cout << "Unable to open file";
    return SegmentList;
}

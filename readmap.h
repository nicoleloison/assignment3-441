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
class List;
List read_map();

/***Segment Object**/
struct Segment {
    string city1, city2;
    int distance, time, gold, trolls, id;
    
    Segment();
    Segment * next;
    
};
Segment::Segment(void){
    /*empty constructor*/
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
    void insert_first();
    void delete_last();
};

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

void List::delete_last()
{
    Segment *current=new Segment;
    Segment *previous=new Segment;
    current=head;
    while(current->next!=NULL)
    {
        previous=current;
        current=current->next;
    }
    tail=previous;
    previous->next=NULL;
    delete current;
}

/*display node*/

void List::display()
{
    Segment *temp=new Segment;
    temp=head;
    while(temp!=NULL)
    {
        cout<< "city1: "<< temp->city1<< " city2: "<< temp->city2 << " distance: "<< temp->distance << " time: "<< temp->time << " gold: "<< temp->gold << " trolls: "<< temp->trolls<< endl;
        temp=temp->next;
    }
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
/*TODO RETURNS LIST SEGM*/
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
        }
        myfile.close();
    }
    
    else cout << "Unable to open file";
    return SegmentList;
}

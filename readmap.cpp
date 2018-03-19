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

string temp_city1, temp_city2;
int temp_distance, temp_time, temp_gold, temp_trolls;

void setDistance( int len );
void setTime (int ti);
void setCity( char * c, string str );
void setGold (int g);
void setTrolls (int t);

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
/**
 Segment::~Segment(void) {
 }
 **/

/*Linked List of Segments */
class List
{
public:
    int number_of_seg;
    Segment * head, * tail;
    List()
    {
        head=NULL;
        tail=NULL;
        number_of_seg=0;
    }
    void create_Node();
    void display();
    void insert_first();
    void delete_last();
};

void List::insert_first()
{
    Segment *temp=new Segment;
    temp->city1=temp_city1;
    temp->city2=temp_city2;
    temp->distance=temp_distance;
    temp->time=temp_time;
    temp->gold=temp_gold;
    temp->trolls=temp_trolls;
    temp->next=head;
    head=temp;
    
    
    cout << "Segment Inserted. " << endl;
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

/*create_node*/
void List::create_Node() {
    number_of_seg++;
    Segment *temp=new Segment;
    temp->city1=temp_city1;
    temp->city2=temp_city2;
    temp->distance=temp_distance;
    temp->time=temp_time;
    temp->gold=temp_gold;
    temp->trolls=temp_trolls;
    temp->id=number_of_seg;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
        tail=temp;
        temp=NULL;
    }
    else
    {
        tail->next=temp;
        tail=temp;
    }
    
    cout << "Node Segment created. " << endl;
}

/*display node*/

void List::display()
{
    Segment *temp=new Segment;
    temp=head;
    while(temp!=NULL)
    {
        cout<<"seg id: "<<temp->id<<" out of: "<<number_of_seg<<endl;
        cout<< "city1: "<< temp->city1<< " city2: "<< temp->city2 << " distance: "<< temp->distance << " time: "<< temp->time << " gold: "<< temp->gold << " trolls: "<< temp->trolls<< endl;
        temp=temp->next;
    }
}
/*distance*/
void setDistance( int len ) {
    if (len< 0 || len > 1000){
        cout << "Invalid Distance. 0<=Distance<=1000 " << endl;
    }
    else{
        temp_distance = len;
        cout << "Set Distance at: "<<temp_distance << endl;
    }
}
/*time*/
void setTime( int ti ) {
    if (ti< 0 || ti > 1000){
        cout << "Invalid Time. 0<=Time<=1000 " << endl;
    }
    else{
        temp_time = ti;
        cout << "Set time at: "<<temp_time << endl;
    }
}
/*cities*/
void setCity( char * c, string str) {
    str.copy( c, sizeof(str), 0 );
    cout << "Segment start at "<<str<< endl;
}

/*gold*/
void setGold( int g ) {
    if (g< 0 || g > 100){
        cout << "Invalid Gold. 0<=Gold<=100 " << endl;
    }
    else{
        temp_gold = g;
        cout << "Set gold at: "<<temp_gold << endl;
    }
}

/*trolls*/
void setTrolls( int t ) {
    if (t< 0 || t > 10){
        cout << "Invalid Trolls number. 0<=trols<=10 " << endl;
    }
    else{
        temp_trolls = t;
        cout << "Set trolls at: "<<temp_trolls << endl;
    }
}
int numerical_data(char* ch, int start){
    char l[4]= {'\0'};
    for (int a =0; a<3;a++){
        l[a]=ch [start+a];
    }
    return atoi(l);
}
/*main*/
int main () {

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
           // cout<< "line len : "<< len<< " last char: "<<cstr[len-1]<<endl;
            char * p = strtok (cstr," ");
             SegmentList.create_Node();
             SegmentList.insert_first();
            while (p!=0)
            {
                int counter =0;
                while (counter<sizeof(cstr)){
                /*
                    temp_city1=cstr[0];
                    temp_city2=cstr[2];
                    temp_distance = numerical_data(cstr,4);
                    temp_time = numerical_data(cstr, 8);
                    temp_gold = numerical_data(cstr, 12);
                    temp_trolls =atoi(&cstr[len-1]);
                    counter++;*/
                    SegmentList.head->city1=cstr[0];
                    SegmentList.head->city2=cstr[2];
                    SegmentList.head->distance= numerical_data(cstr,4);
                    SegmentList.head->time= numerical_data(cstr, 8);
                    SegmentList.head->gold = numerical_data(cstr, 12);
                    SegmentList.head->trolls=atoi(&cstr[len-1]);
                    counter++;
                   
                  
                }
               //cout << p << '\n';
                p = strtok(NULL," ");
               
               
                
            }
           
          
            delete[] cstr;
        }
        myfile.close();
    }
    
    else cout << "Unable to open file";
    SegmentList.display();
    return 0;
}

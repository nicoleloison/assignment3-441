/*GARANCE NICOLE LOISON
 ID 10083186
 CPSC 441 - A3
 
 READLocationS.CPP
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

int numerical_data(char* ch, int start);

/***Hobbit Object**/
struct Location {
    int id;
    string owner, city;
    
    Location();
    Location * next;
    
};
Location::Location(void){
    /*empty constructor*/
}

/*Linked List of Locations */
class List
{
public:
    int number;
    Location * head, * tail;
    List()
    {
        head=NULL;
        tail=NULL;
        number=0;
    }
    void display();
    void insert_first();
    void delete_last();
};

void List::insert_first()
{
    number++;
    Location *temp=new Location;
    
    temp->owner='\0';
    temp->city='\0';
    temp->id=number;
    temp->next=head;
    head=temp;
}

void List::delete_last()
{
    Location *current=new Location;
    Location *previous=new Location;
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
    Location *temp=new Location;
    temp=head;
    while(temp!=NULL)
    {
        cout<< ""<<temp->owner<<" is currently in "<< temp->city << endl;
        temp=temp->next;
    }
}

int numerical_data(char* ch, int start){
    char l[4]= {'\0'};
    for (int a =0; a<3;a++){
        l[a]=ch [start+a];
    }
    return atoi(l);
}

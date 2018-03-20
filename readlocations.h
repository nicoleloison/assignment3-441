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
struct ListLocation;
ListLocation read_locations();

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
struct ListLocation
{
    int number;
    Location * head, * tail;
    ListLocation();
    void display();
    void insert_first();
    void delete_last();
};

ListLocation::ListLocation(void)
{
    head=NULL;
    tail=NULL;
    number=0;
}

void ListLocation::insert_first()
{
    number++;
    Location *temp=new Location;
    
    temp->owner='\0';
    temp->city='\0';
    temp->id=number;
    temp->next=head;
    head=temp;
}

void ListLocation::delete_last()
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

void ListLocation::display()
{
    Location *temp=new Location;
    temp=head;
    while(temp!=NULL)
    {
        cout<< ""<<temp->owner<<" is currently in "<< temp->city << endl;
        temp=temp->next;
    }
}

ListLocation read_locations(){
    ListLocation list;
    
    string line;
    ifstream myfile ("locations.txt");
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            
            char * cstr = new char [line.length()+1];
            strcpy (cstr, line.c_str());
            
            int len = line.length();
            char * p = strtok (cstr," ");
            list.insert_first();
            list.head->owner = p;
            list.head->city=cstr[len-1];
            
            delete[] cstr;
        }
        myfile.close();
    }
    
    else cout << "Unable to open file locations.txt";
    return  list;
}

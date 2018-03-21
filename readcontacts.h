/*GARANCE NICOLE LOISON
 ID 10083186
 CPSC 441 - A3
 
 READCONTACTS HEADER
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;
struct ListHomes;
ListHomes read_contacts();

/***Hobbit Object**/
struct Home {
    int id;
    string first_name, last_name;
    
    Home();
    Home * next;
    
};
Home::Home(void){
    /*empty constructor*/
}

/*Linked List of Homes */
struct ListHomes
{
    ListHomes();
    int number;
    Home * head, * tail;
    void display();
    void insert_first();
    void delete_last();
};

ListHomes::ListHomes(void)
{
    head=NULL;
    tail=NULL;
    number=0;
}
void ListHomes::insert_first()
{
    number++;
    Home *temp=new Home;
    
    temp->first_name='\0';
    temp->last_name='\0';
    temp->id=number;
    temp->next=head;
    head=temp;
}

void ListHomes::delete_last()
{
    Home *current=new Home;
    Home *previous=new Home;
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

void ListHomes::display()
{
    Home *temp=new Home;
    temp=head;
    while(temp!=NULL)
    {
        cout<< "First name: "<<temp->first_name<<"last name: "<< temp->last_name << endl;
        temp=temp->next;
    }
}

ListHomes read_contacts(){
    ListHomes HomeList;
    
    string line;
    ifstream myfile ("contacts.txt");
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            
            char * cstr = new char [line.length()+1];
            strcpy (cstr, line.c_str());
            
            int len = line.length();
            char * p = strtok (cstr," ");
            HomeList.insert_first();
            HomeList.head->first_name = p;
            HomeList.head->last_name=cstr[len-1];
            
            delete[] cstr;
        }
        myfile.close();
    }
    
    else cout << "Unable to open file contacts.txt";
    
    return HomeList;
}



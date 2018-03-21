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
ListLocation  filter_by_city(string filter, ListLocation * list);
ListLocation  filter_by_name(string filter, ListLocation * list);
ListLocation read_locations();


/***Location Object**/
struct Location {
    int id;
    string first_name, city;
    
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
    void append(Location ** head_ref, Location s);
    void delete_last();
    string * get_all_dest();
    string * get_all_names();
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
    
    temp->first_name='\0';
    temp->city='\0';
    temp->id=number;
    temp->next=head;
    head=temp;
}

void ListLocation::append(Location ** head_ref, Location s)
{
    number++;
    Location *new_node= (struct Location*) malloc(sizeof(struct Location));
    Location *last = *head_ref;
    
    new_node->first_name = s.first_name;
    new_node->city=s.city;
    new_node->id = number;
    
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

string * ListLocation::get_all_names(void){
    string  * result = new string[number];
    size_t size = sizeof(result)/ sizeof(string);
    Location *temp=new Location;
    temp=head;
    int index =0;
    
    while(temp!=NULL)
        if (temp->first_name.compare("Bilbo")==0){
            break;
        }
    {
        result[index].assign(temp->first_name);
        //cout<< "name: "<<result[index]<<endl;
        index++;
        temp=temp->next;
    }

    delete temp;
    temp=NULL;
    
    return result;
}

string * ListLocation::get_all_dest(void){
    string  * result = new string[number];
    size_t size = sizeof(result)/ sizeof(string);
    Location *temp=new Location;
    temp=head;
    int index =0;
    
    while(temp!=NULL)
    {
        if (temp->first_name.compare("Bilbo")==0){
            break;
        }
        result[index].assign(temp->city);
        cout<< "src: "<<result[index]<<endl;
        index++;
        temp=temp->next;
    }
    
    delete temp;
    temp=NULL;
    
    return result;
}

/*display node*/

void ListLocation::display()
{
    Location *temp=new Location;
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->first_name<<" lives in "<< temp->city << endl;
        temp=temp->next;
    }
    delete temp;
    temp=NULL;
    
}

ListLocation filter_by_name(string filter, ListLocation * list){
    ListLocation result;
    Location *temp=new Location;
    temp=list->head;
    string str;
    
    while(temp!=NULL)
    {
        str.assign(temp->first_name);
        if (str.compare(filter)==0){
           result.append(&result.head, * temp);
        }
        
        temp=temp->next;
    }
    delete temp;
    temp=NULL;
    
    str.clear();
    return result;
}

ListLocation filter_by_city(string filter, ListLocation * list){
    ListLocation result;
    Location *temp=new Location;
    temp=list->head;
    string str;
    
    while(temp!=NULL)
    {
        str.assign(temp->city);
        if (str.compare(filter)==0){
             result.append(&result.head, * temp);
        }
        
        temp=temp->next;
    }
    delete temp;
    temp=NULL;
    
    str.clear();
    return result;
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
            list.head->first_name = p;
            list.head->city=cstr[len-1];
            
            delete[] cstr;
        }
        myfile.close();
    }
    
    else cout << "Unable to open file locations.txt";
    return  list;
}

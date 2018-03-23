/*GARANCE NICOLE LOISON
 ID 10083186
 CPSC 441 - A3
 
 get address HEADER
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;
int LINES;

string * get_address( string filename ){
    int line_count = 0;
    
    string lino;
    ifstream filo (filename);
    while (std::getline(filo, lino)){
            line_count++;
    }
    LINES = line_count;
    
    string * addresses= new string [line_count+1];
    
    int counter =0;
    string line;
    ifstream myfile (filename);
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            char * cstr = new char [line.length()+1];
        
            strcpy (cstr, line.c_str());
            addresses[counter].assign(cstr);
            delete[] cstr;
            counter++;
        }
        myfile.close();
    }
    
    else cout << "Unable to open file contacts.txt";
    

    
    for (int i = 0; i < line_count; i ++){
        cout << addresses[i]<< endl;
    }
    return addresses;

}

string * get_city (string * addresses){
    string * cities= new string [LINES+1];
   
    for (int i = 0; i < LINES; i ++){
        int le = addresses[i].length();
        cities[i] = addresses[i][le-1];
       // cout << cities[i]<< endl;
        
    }
    
    return cities;
}



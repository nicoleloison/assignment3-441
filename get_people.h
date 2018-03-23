/*GARANCE NICOLE LOISON
 ID 10083186
 CPSC 441 - A3
 
 GETPEOPLE HEADER
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;


string * get_people( string filename ){
    int line_count = 0;
    
    string lino;
    ifstream filo ( filename );
    while (std::getline(filo, lino)){
            line_count++;
    }

    
    
    string * names = new string[line_count+1];
    
    int counter =0;
    string line;
    ifstream myfile ( filename );
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            
            char * cstr = new char [line.length()+1];
            strcpy (cstr, line.c_str());

            char * p = strtok (cstr," ");
            names[counter].assign(p);
        
            
            delete[] cstr;
            counter++;

   
        }
        myfile.close();
    }
    
    else cout << "Unable to open file contacts.txt";

    for (int i = 0; i < line_count; i ++){
        //cout << names[i]<< endl;
      
    }
    return names;

    
    //return 0;
}



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

int city_distance[][];
//city distance maps 2 cities and holds the distance;

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

/* RETURNS 2D array SEGM*/
int main()
{
    string line;
    ifstream myfile ("map.txt");
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
             int c_d[][];
            
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
    return 0;
}
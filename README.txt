
Necessary tools to be installed: 
- g++ for the appropriate OS of running computer to compile C++ code. Download g++ at: http://gcc.gnu.org/install/download.html  
Download the full file including the text files to be read.  

Settings and Limitations:
The main.cpp file has text files and 3 header files dependencies: 
get_address.h: reads from the addresses.txt file and returns the Dwarves and their source city.
get_people.h: reads from the contacts.txt file and returns the Dwarves first names.
graph.h: reads from the map files and compute the statistics of the path taken by the dwarves. The destination is hardcoded to be ‘C’ (Calgary) at the top of the file. Change it to any alphabet letter to compute possible path for the dwarves to the destination. 

Running the program:
Open the terminal and go to the folder of your project. Once there, compile the main.cpp file with g++:
g++ -o main main.cpp
Run the main exec file with 2 arguments: map or fullmap and any of the following minimizing function: “hops” for minimum hops, “distance” for minimum distance, “time” for minimum time, and trolls for minimum trolls. 
	./main map hops
for instance. 
The program will output the following statistics: 
The minimum hops from C for the dwarves are:
Nori can go from E to destination:
going through	1 hops, travelling	 km, for 120 hours, collecting	8 pieces of gold, encountering	2 trolls.


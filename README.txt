Necessary tools to be installed: 
- g++ for the appropriate OS of running computer to compile C++ code. 
- Download the full file including the text files to be read.  
Settings and Limitations:
The main.cpp file has 3 text files and 2 header files dependencies: 
get_address.h: reads from the addresses.txt file and returns the Dwarves and their source city.
graph.h: reads from the map files and compute the statistics of the path taken by the dwarves. The destination is hardcoded to be ‘C’ (Calgary) at the top of the file. Change it to any alphabet letter to compute possible path for the dwarves to the destination. 
Running the program:
Open the terminal and go to the folder of your project. Once there, compile the main.cpp file with g++: 						g++ -o main main.cpp
Run the main exec file with 3 arguments: map or fullmap and any of the following minimizing function: “hops” for minimum hops, “distance” for minimum distance, “time” for minimum time, and trolls for minimum trolls, for instance, and addresses or fulladdresses:	./main map hops addresses.
The address file matches with the map file, and fulladdresses with the fullmap file. The output is such:
The minimum hops from C for the dwarves are:
Nori can go from E to destination:
going through	1 hops, travelling	300 km, for 120 hours, collecting	8 pieces of gold, encountering	2 trolls.
...
Average hops: 1.625, distance: 942, time: 575, gold: 9.875, trolls:4.5
Performance Analysis:

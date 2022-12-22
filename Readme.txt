===Description===
This is the HW4 of the class Data Structure (Deadline - 2022/12/23)
This program is written in Dev cpp.
Name of file : HW4_F74106270.zip
Structure :
|-HW4_F74106270.rar (.zip) 
| |-HW4_F74016270 (Folder)
| | |-dijkstra.cpp
| | |-dijkstra.exe
| | |-prim.cpp
| | |-prim.exe
| | |-output_d.txt
| | |-output_p.txt
| | |-sample_d.txt
| | |-sample_p.txt
| | |-Readme.txt

prim.cpp is a program that defaults that you have 7 nodes and lets you insert the weight of two nodes then prints out the MST calculated by prim's algorithm.
dijkstra.cpp is a program that defaults that you have 7 nodse and lets you insert the weight of the two nodes then prints out the shortest path from designated starting point.


Functions / Class / Input Output File in the program : 
* Node : Struct used to store vector and its weight
* compareByLength : later used to sort the vector according to the node's weight
* main : takes filename from user to take values, then finds the shortest path using Prim's algorithm or Dijkstra's algorithm. 
         Lastly, print out the result accroding to the weight of the path to according output file.
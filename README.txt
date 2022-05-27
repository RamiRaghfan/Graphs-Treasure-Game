--------------------------------------------------------------------------------
REQUIRES C++ COMPILER OR IDE TO WORK

1. Extract all files into a single folder
2. Compile and tun using your preferred method
3. Review input and output files
--------------------------------------------------------------------------------
Graph class is taken from the Data Structures lab. 

Function descriptions

resetGraph(int *visited)

int *visited - array of integers representing the state of the node (visited or not visited)

Iteratively sets array to zeroes

--------------------------------------------------------------------------------

void passwordCheckUtil(string pwd, int x, int i, vector<int> &path)

string pwd - string conatining the characters that are supposed to be found by traversal
int x - node number of the graph
int i - index variable for char by char traversal of the string 
vector<int> &path - list for storing the correct path

A modified DFS function that breaks out of the recursive stack as soon as soon as it encounters
incorrect nodes based on the currect character (nodes in the graph have characters as keys or
"payloads)".
--------------------------------------------------------------------------------
void passwordCheck(string password)


string password - the string containing the sequence of characters that are supposed to be
found on the graph, also as a sequence of connected nodes. 

This function first looks for the first node in the graph that contains the first char in the
password AND has a neighbor representing the next char in the password.
Calls passwordCheckUtil(string pwd, int x, int i, vector<int> &path), the correct path should be
equal size with the string size. 

--------------------------------------------------------------------------------

bool hasNext(int i, char c)

int i - starting index(vertex)
char c - character to look for in the neightbor

Searches the neigbors of vertex i for character c, returns true if a match is found,
false if nothing is found  

--------------------------------------------------------------------------------



NP Coloring coloring algorithm:


bool isValid(int vtx, int stones, int v)

int vtx - current vertex to color
int stones[] - array of colored colors 
int c - color to use

Checks if a color assighment is valid for the surrounding neighbors
(no two neighbors with the same colors should exist)

--------------------------------------------------------------------------------
bool graphColoringHelper(int maxStones, int stones[], int v)

int maxStones - max colors to use, number should not be exceeded 
int stones[] - array of colored nodes
int v - counter variable to advance nodes

Recursive function to help solve the coloring, and assign colors

--------------------------------------------------------------------------------
bool graphColoring(int maxStones)



int maxStones - maximum colors to be used, shall not be exceeded for a colored graph
Function that uses backtracking to solve the coloring problem, calling graphColoringHelper() 
mainly.

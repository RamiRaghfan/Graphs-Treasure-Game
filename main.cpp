#include "TreasureRoom.h"

Graph<char> lck(10);
int visited[9];


void resetGraph(int *visited)
{
    for (int i = 0; i < lck.N; i++)   
    {
        visited[i] = 0;
    }
}

void passwordCheckUtil(string pwd, int x, int i, vector<int> &path)
{

    int y;
    if(lck.getNodeInfo(x) == pwd[i])
    {
        path.push_back(x);
    }
    else
    {
        return;
    }

    visited[x] = 1;

    for (y = 0; y < lck.N; y++)
        if (lck.A[x][y] && !visited[y]) 
        {
            passwordCheckUtil(pwd, y, i+1, path);
        }
}


bool hasNext(int i, char c)
{
    for(int j = 0; j < lck.N; j++)
    {
        if(lck.A[i][j] == 1 && lck.getNodeInfo(j) == c)
        {
            return true;
        }
    }
    return false;

}


void passwordCheck(string password)
{

    vector<int> path;

    transform(password.begin(), password.end(), password.begin(), ::toupper);


    string result = "no\n";
    for(int j = 0; j < lck.N; j++)
    {
        if(password[0] == lck.getNodeInfo(j) && hasNext(j, password[1]))
        {
            passwordCheckUtil(password, j, 0, path); 

            if(password.size() == path.size())
            {
                result = "yes ";
                for(int i = 0; i < path.size(); i++)
                {
                    result = result + " " + to_string(path[i]);
                }

                result = result + '\n';
                break;
            }


        } 

    }

    cout << result; 

}


//Checks if stones assigmnet made is valid

bool isValid(int vtx, int stones[], int c)
{
    for(int i = 0; i < lck.N; i++)
    {
        if(lck.A[vtx][i] && c == stones[i]) 
        {
            return false;
        }
    }

    return true;
}

bool graphColoringHelper(int maxStones, int stones[], int v)
{
    if(v == lck.N)
        return true;

    for(int s = 1; s <= maxStones; s++)
    {
        if(isValid(v, stones, s))
        {
            stones[v] = s;

            if(graphColoringHelper(maxStones, stones, v+1) == true)
            {
                return true;
            }

            stones[v] = 0;
        }
    }

    return false;
}


bool graphColoring(int maxStones)
{
    int stones[lck.N];
    for(int i = 0; i < lck.N; i++) 
    {
        stones[i] = 0;
    }

    bool canBeColored = graphColoringHelper(maxStones, stones, 0);
    if(canBeColored == false)
    {
        cout << "Argument invalid: The lock cannot be filled with " << maxStones << " stones." << endl;
        return false;
    }

    cout << "The lock can be filled with " << maxStones << " stones" << endl;
    cout<<"\nThe teasure is yours to take!";
    return true;
}


int main() {



    //setting i/o streams to files.
    ifstream file("input.in");
    freopen("BOOTY!!!.out", "w", stdout);
    string line, nodeLetters;


    getline(file, nodeLetters);

    int j = 0;
    for (int i = 0; i < nodeLetters.size(); i++) 
    {
        lck.setNodeInfo(j, nodeLetters[i]);
        j++;
    }

    while(getline(file, line))
    {
        int node1 = line[0]-'0';
        int node2 = line[2]-'0';

        lck.addEdge(node1, node2);
    }

    resetGraph(visited);
    string passwordTests[4] = {"parrot", "rum", "argh", "arrgh"};

    for (string* p = &passwordTests[0]; p != &passwordTests[4]; ++p) 
    {
        resetGraph(visited);
        cout << *p << " -- ";
        passwordCheck(*p);
        cout << endl;
    }


    resetGraph(visited);
    cout<<"\nTrying with 2 stones..\n";
    graphColoring(2);

    resetGraph(visited);
    cout<<"\n\nTrying with 3 stones..\n";
    graphColoring(3);

}
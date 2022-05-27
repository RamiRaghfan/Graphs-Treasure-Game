#include <iostream>
#include<algorithm>
#include <vector>
#include<fstream>
#include <queue>


using namespace std;
template<typename TnodeInfo>
class Graph {
public:

    int N;
    char **A;
    TnodeInfo *nodeInfo;

    Graph(int numNodes)
    {
        int i, j;

        N = numNodes;

        // allocate the adjacency matrix
        A = new char*[N];
        for (i = 0; i < N; i++)
        {
            A[i] = new char[N];
        }

        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
            {
                A[i][j] = 0;
            }
        }

        // allocate t he array with node information
        nodeInfo = new TnodeInfo[N];

    }

    void setNodeInfo(int i, TnodeInfo info) 
    {
        nodeInfo[i] = info;
    }

    TnodeInfo getNodeInfo(int i) 
    {
        return nodeInfo[i];
    }

    void addEdge(int i, int j) {
        A[i][j] = A[j][i] = 1;
    }

    void removeEdge(int i, int j)
    {
        A[i][j] = A[j][i] = 0;
    }

};








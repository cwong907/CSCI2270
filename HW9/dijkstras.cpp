// Dijkstra's lecture code snippets 
#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct adjVertex
{ // EDGE 
    vertex *v;
    int weight;
};

struct vertex
{
    // Key value
    std::string name;
    // adjacency list
    std::vector<adjVertex> adj;
    
    // visited member for Breadth First Traverse
    bool visited = false;
    // distance member for BFT
    int distance = 0;

    // solved member for Dijkstra's
    bool solved = false;
    // distDijk for weighted distance
    int distDijk = 0;
};


void Graph::dijkstraTraverse(string sourceVertex)
{
    vertex *vStart = search(sourceVertex);
    if(!vStart){
        // error message
        return;
    }

    cout << "Starting vertex (root)" << vStart->name << " ->";

    vStart->solved = true;
    vStart->distDijk = 0;

    // Create a list to store the solved vertices
    // and append vStart
    vector<vertex*> solvedList;
    solvedList.push_back(vStart);

    // Set a boolean variable to let us know
    // when Dijkstra's is completed on
    // entire  graph

    bool allSolved = false;

    while(!allSolved)
    {
        int minDist = INT_MAX;
        // pointer to keep track of solved node
        vertex *solvedV = nullptr;
        allSolved = true;
        // iterate across list of solved vertices
        for(int i = 0; i<solvedList.size(); i++)
        {
            vertex *s = solvedList[i];
            // now iterate s's adj list
            for(int j = 0; j<s->adj.size(); j++)
            {
                if(!s->adj[j].v->solved)
                {
                    // calculate the distance from vStart
                    int dist = s->distDijk + s->adj[j].weight;
                    // check if the distance is less than 
                    // smallest distance thus far
                    if(dist<minDist)
                    {
                        solvedV = s->adj[j].v;
                        minDist = dist;
                    }
                    allSolved = false;
                }
            }
        }

        if(!allSolved)
        {
            // Update the new vertex shorest path
            solvedV->distDijk = minDist;
            // Mark vertex as solved
            solvedV->solved = true;

            // Append the solved vertex to "solved list"
            solvedList.push_back(solvedV);
            cout << solvedV->name << " "<< solvedV->distDijk << " " ;  
        }
    }
}



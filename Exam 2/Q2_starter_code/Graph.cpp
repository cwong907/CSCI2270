#include "Graph.hpp"
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

void Graph::addEdge(string source, string target)
{
    for(unsigned int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i]->name == source)
        {
            for(unsigned int j = 0; j < vertices.size(); j++)
            {
                if(vertices[j]->name == target && i != j)
                {
                    adjVertex av;
                    av.v = vertices[j];
                    vertices[i]->adj.push_back(av);
                }
            }
        }
    }
}

void Graph::addVertex(string vName)
{
    bool found = false;
    for(unsigned int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i]->name == vName)
        {
            found = true;
            cout<<vertices[i]->name<<" found."<<endl;
        }
    }
    if(found == false)
    {
        vertex * v = new vertex;
        v->name = vName;
        v->distance = 0;
        vertices.push_back(v);
    }
}

void Graph::displayEdges()
{
    for(unsigned int i = 0; i < vertices.size(); i++)
    {
        cout<<vertices[i]->name<<":"<<endl;
        for(unsigned int j = 0; j < vertices[i]->adj.size(); j++)
        {
            cout<<" --> "<< vertices[i]->adj[j].v->name <<endl;
        }
        cout<<endl;
    }
}

bool Graph::isStronglyConnected()
{
    /* 
    Implement this function. 
    This function returns true if the graph is strongly connected. Otherwise, returns false.
    */

    //Mark all the vertices as not visited just in case
    //bool visited[V]; 
    for (int i = 0; i < V; i++) 
        visited[i] = false; 
  
    Do DFS traversal starting from first vertex. 
    DFSUtil(0, visited); 
  
     // If DFS traversal doesn’t visit all vertices, then return false. 
    for (int i = 0; i < V; i++) 
        if (visited[i] == false) 
             return false; 
  
    // Step 3: Create a reversed graph 
    Graph gr = getTranspose(); 
  
    // Step 4: Mark all the vertices as not visited (For second DFS) 
    for(int i = 0; i < V; i++) 
        visited[i] = false; 
  
    // Step 5: Do DFS for reversed graph starting from first vertex. 
    // Staring Vertex must be same starting point of first DFS 
    gr.DFSUtil(0, visited); 
  
    // If all vertices are not visited in second DFS, then 
    // return false 
    for (int i = 0; i < V; i++) 
        if (visited[i] == false) 
             return false; 
  
    return true; 
}
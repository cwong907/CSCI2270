#include<vector>
#include<iostream>
#include<queue>
#include "Graph.hpp"
using namespace std;

void Graph::addVertex(string name)
{
    bool found = false;
    //checks the vertices vector to see if a vertex already exists
    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i]->name == name)
        {
            found = true;
            //cout << "Name already exists." << endl;
        }
    }

    if(found == false)
    {
        vertex *n = new vertex;
        n->name = name;
        vertices.push_back(n);
    }
}

void Graph::addEdge(string v1, string v2)
{
    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i]->name == v1)
        {
            for(int j = 0; j < vertices.size(); j++)
            {
                if(vertices[j]->name == v2 && i != j)
                {
                    adjVertex connect;
                    connect.v = vertices[j];
                    vertices[i]->adj.push_back(connect);

                    adjVertex connect2;
                    connect2.v = vertices[i];
                    vertices[j]->adj.push_back(connect2);
                }
            }
        }
    }
}

void Graph::displayEdges()
{
    for(int i = 0; i < vertices.size(); i++)
    {
        cout << vertices[i]->name << " --> ";
        for(int j = 0; j < vertices[i]->adj.size(); j++)
        {
            cout << vertices[i]->adj[j].v->name << " ";
        } 
        cout << endl;
    }
}

void Graph::breadthFirstTraverse(string sourceVertex)
{
    // Finds the source vertex since we only have it's key
    // A pointer for source vertex
    vertex *startVert;

    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i]->name == sourceVertex)
        {
            startVert = vertices[i];
        }
    }
    startVert->visited = true;
    // Use the queue to keep track of visited vertices
    queue<vertex*> visited;
    // Enqueue the source vertex
    visited.push(startVert);
    cout << "Starting vertex (root): " << startVert->name << "-> ";

    vertex* n;
    // standard BFS
    while(!visited.empty())
    {
        n = visited.front();
        visited.pop();

        // go to all the adjacent vertices of n
        for(int w = 0; w < n->adj.size(); w++)
        {
            // If a adjacent has not been visited, then mark it visited and enqueue it
            // Update the distance of the adjacent vertices along the way
            vertex*n2 = n->adj[w].v;
            if(n2->visited == false)
            {
                n2->visited = true;
                n2->distance = n->distance + 1;
                visited.push(n2);
                cout << n2->name << "(" << n2->distance << ")" << " ";
            }
        }

    }
}

void DFTraversal(vertex *n)
{
    n->visited = true;

    for(int x = 0; x < n->adj.size(); x++ )
    {
        if(!n->adj[x].v->visited)
        {
            DFTraversal(n->adj[x].v);
        }
    }
}

int Graph::getConnectedComponents()
{
    int connectedNodes = 0;

    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i]->visited == false)
        {
            DFTraversal(vertices[i]);
            connectedNodes++;
        }
    }

    return connectedNodes;
}
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

void Graph::addEdge(string v1, string v2, int num)
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
                    connect.weight = num;
                    connect.v = vertices[j];
                    vertices[i]->adj.push_back(connect);

                    adjVertex connect2;
                    connect2.weight = num;
                    connect2.v = vertices[i];
                    vertices[j]->adj.push_back(connect2);
                }
            }
        }
    }
}

void Graph::depthFirstTraversal(string sourceVertex)
{
    vertex* foundIt = NULL;
    int unvisited = 0;

    for (int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i]->name == sourceVertex)
        {
            foundIt = vertices[i];
        }
    }
    
    for (int i = 0; i < foundIt->adj.size(); i++)
    {
        if(foundIt->adj[i].v->visited == false)
        {
            unvisited++;
        }
    }

    foundIt->visited = true; 

    cout << foundIt->name << " -> ";

    for(int x = 0; x < foundIt->adj.size(); x++ )
    {
        if(!foundIt->adj[x].v->visited)
        {
            depthFirstTraversal(foundIt->adj[x].v->name);
        }
    }

    if(unvisited == foundIt->adj.size())
    {
        cout << "Done" << endl;
    }

}

void Graph::shortestPath(string start, string end)
{
    dijkstraTraverse(start);

    vertex *begin = NULL;
    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i]->name == start)
        {
            begin = vertices[i];
        }
    }
    
    vertex *finish = NULL;
    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i]->name == end)
        {
            finish = vertices[i];
        }
    }

    vertex *crawl = finish;
    vector<string> thing;
    while(crawl != begin)
    {
        thing.push_back(crawl->name);
        crawl = crawl->pred;
    }

    cout << begin->name << " -> ";

    //start from end of vector and go to end
    for(int i = thing.size() - 1; i >= 0; i--)
    {
        cout << thing[i] << " -> ";
    }
    cout << "DONE " << "[" << finish->distance << "]" << endl;
}

void Graph::dijkstraTraverse(string start)
{
    vertex* begin = NULL;

    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i]->name == start)
        {
            begin = vertices[i];
        }
    }

    begin->visited = true;
    begin->distance = 0;

    vector<vertex*> solvedList;
    solvedList.push_back(begin);

    bool allSolved = false;

    while(!allSolved)
    {
        int minDist = 1000000;
        // pointer to keep track of solved node
        vertex *solvedV = nullptr;
        allSolved = true;
        // iterate across list of solved vertices
        for(int i = 0; i < solvedList.size(); i++)
        {
            vertex *s = solvedList[i];
            // now iterate through s's adj list
            for(int j = 0; j<s->adj.size(); j++)
            {
                if(!s->adj[j].v->visited)
                {
                    // calculate the distance from vStart
                    int dist = s->distance + s->adj[j].weight;
                    // check if the distance is less than 
                    // smallest distance thus far
                    if(dist < minDist)
                    {
                        solvedV = s->adj[j].v;
                        minDist = dist;
                        solvedV->pred = s;
                    }
                    allSolved = false;
                }
            }
        }

        if(!allSolved)
        {
            // Update the new vertex shorest path
            solvedV->distance = minDist;
            // Mark vertex as solved
            solvedV->visited = true;

            // Append the solved vertex to "solved list"
            solvedList.push_back(solvedV);
            cout << solvedV->name << " "<< solvedV->distance << " " ;  
        }
    }
}


/*
    dijkstraTraverse(start);
    vector<string> path;
    vertex *begin = NULL;
    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i]->name == start)
        {
            begin = vertices[i];
        }
    }
    vertex *finish = NULL;
    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i]->name == end)
        {
            finish = vertices[i];
        }
    }

    vertex* walk = finish;
    while(walk != begin)
    {
        path.push_back(walk->name);
        walk = walk->pred;
    }
    // names.push_back(walk->name);
    int num = path.size();
    cout << begin->name << " -> ";
    for(int i = 0; i < path.size(); i++)
    {
        cout << path[num-1] << " -> ";
        num--;
    }
    cout << "DONE " << "[" << finish->distance << "]" << endl;
*/
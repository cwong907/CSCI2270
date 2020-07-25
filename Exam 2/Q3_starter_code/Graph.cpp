#include "Graph.hpp"
#include <vector>
#include <queue>
#include <iostream>
#include <queue>

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
        vertices.push_back(v);
    }
}

void Graph::display()
{
    cout<<"vertex"<<":"<<"color"<<endl;
    for(unsigned int i = 0; i < vertices.size(); i++)
    {
        cout<<vertices[i]->name<<":"<<vertices[i]->color<<endl;

    }
}

void Graph::color(string source)
{
  //TODO
  //start on the vertex given, change the color to black and mark it as visited
  //then for loop through the adjencency list of that starting vertex and check if they have been visited, if not color everything in that vector red and visited
  //go to those vertex's anjenceny list and for everything unvisited in their adjencency list, mark them visited and black 
  //repeat except with alternating colors

  for(int i = 0; i < vertices.size(); i++)
  {
      //searches through the vertex vector for the starting point we are given
      if(vertices[i]->name == source)
      {
          //marks black and visited
          vertices[i]->visited == true;
          vertices[i]->color == "black";

          //searches the starting point's adj list and unvisited ones are marked visited and red        
          for(int j = 0; j < vertices[i]->adj.size(); j++)
          {
              if(vertices[i]->adj[j].v->visited == false)
              {
                vertices[i]->adj[j].v->visited == true;
                vertices[i]->adj[j].v->color == "red";
              }
          }

          //then traverse the adjencency list of those nodes and find unvisited adj nodes then mark them visited and black     
          //repeat this until with alternating colors until everythinh has been visited     
      }
  }
}

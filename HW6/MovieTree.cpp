#include "MovieTree.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

// MovieNode: node struct that will be stored in the MovieTree BST

MovieTree::MovieTree() 
{
  root = NULL;
}

void Obliterate(MovieNode *currNode)
{
  if(currNode == NULL)
  {
    return;
  }

  else
  {
    Obliterate(currNode->left);
    Obliterate(currNode->right);
    delete currNode;
  }
}

MovieTree::~MovieTree() 
{
  Obliterate(root);
}

void MovieTree::findMovie(string title)
{
  MovieNode *search = root;

  while(true)
  {
    if(title < search->title && search->left != NULL)
    {
      search = search->left;
    }

    else if(title > search->title && search->left != NULL)
    {
      search = search->right;
    }

    else if(title == search->title)
    {
      cout << "Movie Info:" << endl;
      cout << "==================" << endl;
      cout << "Ranking: " << search->ranking << endl;
      cout << "Title: " << search->title << endl;
      cout << "Year: " << search->year << endl;
      cout << "rating: " << search->rating << endl;
      break;
    }

    else
    {
      cout << "Movie not found." << endl;
      break;
    }
  }
}

void imConfused(MovieNode *current, int &counter)
{
  counter++;

  if(current == NULL)
  {
    if(counter == 1)
    {
      cout << "Tree is Empty. Cannot print" << endl;
    }

    else
    {
      return;
    }
}

  else
  {
    imConfused(current->left, counter);

    cout << "Movie: " << current->title << " " << current->rating << endl;

    imConfused(current->right, counter);
  }
}

void MovieTree::printMovieInventory() 
{
  int count = 0;
  imConfused(root, count);  
}

void MovieTree::addMovieNode(int ranking, string title, int year, float rating) 
{
  MovieNode *point = new MovieNode(ranking, title, year, rating);

  if(root == NULL)
  {
    root = point;
    return;
  }

  else
  {
    MovieNode *check;
    check = root;

    while(check != NULL)
    {
      if(title > check->title && check->right == NULL)
      {
        check->right = point;
        break;
      }

      else if(title < check->title && check->left == NULL)
      {
        check->left = point;
        break;
      }

      else if(title < check->title && check->left != NULL)
      {
        check = check->left;
      }

      else
      {
        check = check->right;
      }
    }
  }
}

void searchMovie(MovieNode *find, float rating, int year)
{
  if(find ==  NULL)
  {
    return;
  } 

  if(find->rating >= rating && find->year > year)
  {
    cout << find->title << "(" << find->year << ") " << find->rating << endl; 
  }  

  searchMovie(find->left, rating, year);
  searchMovie(find->right, rating, year); 
}

void MovieTree::queryMovies(float rating, int year) 
{
  if(root == NULL)
  {
    cout << "Tree is Empty. Cannot query Movies" << endl;
  }

  else
  {
    cout << "Movies that came out after " << year << " with rating at least " << rating << ":" << endl;

    searchMovie(root, rating, year);
  }  
}

float sumNodeValue(MovieNode *node)
{
  if(node != NULL)
  {
      return(node->rating + sumNodeValue(node->left) + sumNodeValue(node->right));
  }
  else
  {
      return 0;
  }
  
}

int sumNodes(MovieNode *node)
{
  if(node != NULL)
  {
      return(1 + sumNodes(node->left) + sumNodes(node->right));
  }
  else
  {
    return 0;
  }
  
}

void MovieTree::averageRating() 
{
  if(root == NULL)
  {
    cout << "Average rating:0.0" << endl;
  }

  else
  {
    float totalValue = sumNodeValue(root);
    int numNodes = sumNodes(root);

    cout << "Average rating:" << totalValue/numNodes << endl;
  }
}

void helpPrint(MovieNode *there, int level, int counter)
{ 
  if(there == NULL)
  {
    return;
  }

  else if(counter == level && there != NULL)
  {
    cout << "Movie: " << there->title << " " << there->rating << endl;
  }

  else  
  {
    counter++;
    helpPrint(there->left, level, counter);
    helpPrint(there->right, level, counter);
  }
}

void MovieTree::printLevelNodes(int level) 
{
  int counter = 0;
  helpPrint(root, level, counter);
}
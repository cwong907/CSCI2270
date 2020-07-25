#include <iostream>
#include <fstream>
#include "MovieTree.hpp"

using namespace std;

/* ------------------------------------------------------ */
MovieTree::MovieTree()
{
	root = NULL;
}

void deleteN(TreeNode* temp) 
{
  if(temp == NULL)
  {
    return;
  }
  if (temp->leftChild != NULL) 
  {
    deleteN(temp->leftChild);
  }
  if (temp->rightChild != NULL) 
  { 
    deleteN(temp->rightChild);
  }

  if (temp->head != NULL) 
  {
    LLMovieNode* del;
    while (temp->head != NULL)
    {
      del = temp->head;
      temp->head = temp->head->next;
      delete del;
    }
    temp->head = NULL;
  }
  delete temp;
}

MovieTree::~MovieTree()
{
  deleteN(root);
  //delete root;
  root = NULL;
}

void helpPrint(TreeNode *current, int &counter)
{
  counter++;

  if(current == NULL)
  {
    if(counter == 1)
    {
      return;
    }

    else
    {
      return;
    }
  }

  else
  {
    LLMovieNode *move = current->head;
    helpPrint(current->leftChild, counter);

    cout << "Movies starting with letter: " << current->titleChar << endl;

    while(move != NULL)
    {
        cout << " >> " << move->title << " " << move->rating << endl;
        move = move->next;
    }

    helpPrint(current->rightChild, counter);
  }
}

void MovieTree::printMovieInventory()
{
    int count = 0;
    helpPrint(root, count);
}

void LLInsert(TreeNode *check, LLMovieNode *temp, string title)
{
    LLMovieNode *search = check->head;

    if(check->head == NULL)
    {
        search = temp;
        temp->next = NULL;
    } 

    else if(check->head->title > title)
    {
        temp->next = check->head;
        check->head = temp;
    }  
    
    else
    {
        while(search->next != NULL)
        {
            if(search->title < title && search->next->title > title && search->next != NULL)
            {
                temp->next = search->next;
                search->next = temp;
                break;
            }

            else if(search->title < title && search->next != NULL)
            {
                search = search->next;
            }
        }

        search->next = temp;
    }    
}

void spinMeRightRound(TreeNode *&current, TreeNode *&root)
{
  if(current->rightChild == NULL)
  {
    return;
  }

  else if(current == root)
  {
    TreeNode *temp = current->rightChild;
    temp->parent = NULL;
    current->rightChild = temp->leftChild;
    current->parent = temp;
    temp->leftChild = current;
    root = temp;
  }

  else
  {
    TreeNode *temp = current->rightChild;
    TreeNode *P = current->parent;
    temp->parent = P;

    if(P->rightChild == current)
    {
       P->rightChild = temp;
    }

    else
    {
      P->leftChild = temp;
    }
    current->rightChild = temp->leftChild;
    current->parent = temp;
    temp->leftChild = current;
  }
  
}

void MovieTree::leftRotation(TreeNode* curr)
{
  spinMeRightRound(curr, root);  
}

//------ Given Methods--------//
void _grader_inorderTraversal(TreeNode *root)
{
	if (root == NULL) 
  {
		return;
	}

	_grader_inorderTraversal(root->leftChild);
	cout << root->titleChar << " ";
	_grader_inorderTraversal(root->rightChild);
}


void MovieTree::inorderTraversal() 
{
	_grader_inorderTraversal(root);
	cout << endl;
}

TreeNode* searchCharHelper(TreeNode* curr, char key)
{
    if (curr == NULL)
        return curr;
    else if(curr->titleChar == key)
        return curr;
    else if (curr->titleChar > key)
        return searchCharHelper(curr->leftChild, key);
    else
        return searchCharHelper(curr->rightChild, key);
}

TreeNode* MovieTree::searchChar(char key)
{
    return searchCharHelper(root, key);
}

void MovieTree::addMovie(int ranking, string title, int year, float rating)
{
  TreeNode *check = root;
  if(root == NULL)
  {
    //cout << "Test" << endl;
    TreeNode *x = new TreeNode;
    root = x;
    x->titleChar = title.at(0);
    x->head = new LLMovieNode(ranking, title, year, rating);
    return;
  }

  else
  {
    //cout << "Test2" << endl;
    LLMovieNode *temp = new LLMovieNode(ranking, title, year, rating);
    while(true)
    {
      if(title.at(0) == check->titleChar)
      {
        //cout << "Test3" << endl;
        LLInsert(check, temp, title);
        return;
      }

      else if(title.at(0) > check->titleChar && check->rightChild != NULL)
      {
          //cout << "Test4" << endl;
        check = check->rightChild;
      }

      else if(title.at(0) < check->titleChar && check->leftChild != NULL)
      {
        //cout << "Test5" << endl;
        check = check->leftChild;
      }

      else if(title.at(0) < check->titleChar && check->leftChild == NULL)
      {
        //cout << "ef" << endl;
        TreeNode *newN = new TreeNode;
        newN->titleChar = title.at(0);
        newN->head = temp;
        check->leftChild = newN;
        newN->parent = check;
        //cout << "Test6" << endl;
        return;
      }

      else if(title.at(0) > check->titleChar && check->rightChild == NULL)
      {
        //cout << "F" << endl;
        TreeNode *newN = new TreeNode;
        newN->titleChar = title.at(0);
        newN->head = temp;
        check->rightChild = newN;
        newN->parent = check;
        //cout << "Test7" << endl;
        return;
      }
    }
  }
}

TreeNode* getMinValueNode(TreeNode* currNode)
{

    if(currNode->leftChild == NULL){
      return currNode;
    }
    return getMinValueNode(currNode->leftChild);
}

TreeNode* deleteNode(TreeNode *currNode, char titleC)
{
    if(currNode == NULL)
    {
      return NULL;
    }

    // else if(currNode->parent == NULL)
    // {
    //   currNode = currNode->rightChild;
    // }

    else if(titleC < currNode->titleChar)
    {
      currNode->leftChild = deleteNode(currNode->leftChild, titleC);
    }

    else if(titleC > currNode->titleChar)
    {
      currNode->rightChild = deleteNode(currNode->rightChild, titleC);
    }

    else
    {
      if(currNode->leftChild == NULL && currNode->rightChild == NULL)
      {
          delete currNode;
          currNode = NULL;
          return NULL;
      }
      //Only right child
      else if(currNode->leftChild == NULL && currNode->rightChild != NULL)
      {
          TreeNode *temp = currNode->rightChild;
          currNode->rightChild->parent = currNode->parent;
          delete currNode;
          currNode = temp;
      }
      //Only left child
      else if(currNode->rightChild == NULL && currNode->leftChild != NULL)
      {
          TreeNode *temp = currNode->leftChild;
          currNode->leftChild->parent = currNode->parent;
          delete currNode;
          currNode = temp;
      }
      //Both left and right child
      else
      {
        TreeNode *temp = getMinValueNode(currNode->rightChild);
        currNode->head = temp->head;
        currNode->titleChar = temp->titleChar;
        currNode->rightChild = deleteNode(currNode->rightChild, temp->titleChar);
      }
    }
    return currNode;
}

void MovieTree::deleteMovie(string title)
{
    TreeNode *check = searchChar(title.at(0));

    if(check == NULL)
    {
      cout << "Movie: " << title << " not found, cannot delete." << endl;
    }

    else
    {
        LLMovieNode *look = check->head;
        LLMovieNode *prev = look;

        if(check->head->title == title && check->head->next == NULL)
        {
            //check->head = NULL;
            delete check->head;
            root = deleteNode(root, check->titleChar);
        }

        else if(check->head->title == title)
        {
            //cout << 4 << endl;
            check->head = check->head->next;
            delete look;
        }
        
        else
        {
            //cout << 5 << endl;
            while(look != NULL)
            {
                //cout << 6 << endl;
                if(look->title == title)
                {
                    //cout << 7 << endl;
                    prev->next = look->next;
                    delete look;
                    break;
                }

                else if(look->title == title && look->next == NULL)
                {
                    prev->next = NULL;
                    delete look;
                    break;
                }

                else
                {
                    prev = look;
                    look = look->next;
                }
            } 

            if(look == NULL)
            {
                cout << "Movie: " << title << " not found, cannot delete." << endl; 
            }
        }
    }
}
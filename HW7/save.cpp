TreeNode* deleteNode(TreeNode *currNode)
{
    if(currNode->leftChild == NULL && currNode->rightChild == NULL)
    {
        //cout << "1" << endl;
        delete currNode;
        //cout << "2" << endl;
        currNode = NULL;
        return NULL;
    }
    //Only right child
    else if(currNode->leftChild == NULL)
    {
        TreeNode *temp = currNode->rightChild;
        currNode->parent->rightChild = temp;
        //cout << "3" << endl;
        delete currNode;
        //cout << "4" << endl;
        return temp;
    }
    //Only left child
    else if(currNode->rightChild == NULL)
    {
        if(currNode->parent->leftChild)
        TreeNode *temp = currNode->leftChild;
        currNode->parent->leftChild = temp;
        //cout << "5" << endl;
        delete currNode;
        //cout << "6" << endl;
        return temp;
    }
    //Both left and right child
    else
    {
        //cout << "fsd" << endl;
        TreeNode *temp = getMinValueNode(currNode->rightChild);
        currNode->rightChild = deleteNode(currNode->rightChild);
        return temp;
    }
}

TreeNode * deleteNode(TreeNode* TBD, TreeNode *move)
{
  
}

void MovieTree::deleteMovie(string title)
{
    TreeNode *check = root;
    while(check != NULL)
    {
        //cout << 1 << endl;
      if(title.at(0) == check->titleChar)
      {
          //cout << 2 << endl;
        LLMovieNode *look = check->head;
        LLMovieNode *prev = look;

        if(check->head->title == title && check->head->next == NULL)
        {
            //cout << 3 << endl;
            delete check->head;
            check->head = NULL;
            //cout << 1 << endl;
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
                    //cout << 8 << endl;
                    prev->next = NULL;
                    delete look;
                    break;
                }

                else
                {
                    //cout << 9 << endl;
                    prev = look;
                    look = look->next;
                }
            } 

            if(look == NULL)
            {
                cout << "Movie: " << title << " not found, cannot delete." << endl; 
            }
            
        }

        if(check->head == NULL)
        {
            root = deleteNode(check, root);
        } 
        return;
      }

      else if(title.at(0) > check->titleChar && check->rightChild != NULL)
      {
        check = check->rightChild;
      }

      else if(title.at(0) < check->titleChar && check->leftChild != NULL)
      {
        check = check->leftChild;
      }
    }

    if(check == NULL)
    {
        cout << "Movie: " << title << " not found, cannot delete." << endl;
    }
}


///////////////////////////////////////////////////////////////////////////////
TreeNode* deleteNode(TreeNode *currNode)
{
    if(currNode->leftChild == NULL && currNode->rightChild == NULL)
    {
        delete currNode;
        currNode = NULL;
        return NULL;
    }
    //Only right child
    else if(currNode->leftChild == NULL)
    {
        TreeNode *temp = currNode->rightChild;
        currNode->parent->rightChild = temp;
        delete currNode;
        //cout << "4" << endl;
        return temp;
    }
    //Only left child
    else if(currNode->rightChild == NULL && currNode->leftChild != NULL)
    {
        if(currNode->parent->leftChild == currNode)
        { 
          //cout << "2" << endl;
          currNode->parent->rightChild = currNode->leftChild;
          currNode->leftChild->parent = currNode->parent;
        }
        
        else
        {
          //cout << "3" << endl;
          currNode->parent->rightChild = currNode->rightChild;
          currNode->rightChild->parent = currNode->parent;
        }
        TreeNode *temp = currNode->leftChild;
        delete currNode;
        return temp;
    }
    //Both left and right child
    else
    {
      //cout << "fsd" << endl;
      // TreeNode *temp = getMinValueNode(currNode->rightChild);
      // currNode->rightChild = deleteNode(currNode->rightChild);
      // return temp;
    }
}
/*
1) searchChar
2) check for the test case of if you need to delete the BST node
3) if you don’t need to delete the BST node just delete the linked list node like normal
0) check if the movie exist
*/

void MovieTree::deleteMovie(string title)
{
    TreeNode *check = root;
    while(check != NULL)
    {
        //cout << 1 << endl;
      if(title.at(0) == check->titleChar)
      {
        LLMovieNode *look = check->head;
        LLMovieNode *prev = look;

        if(check->head->title == title && check->head->next == NULL)
        {
            //check->head = NULL;
            delete check->head;
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

        if(check->head == NULL)
        {
           deleteNode(check);
        } 
        return;
      }

      else if(title.at(0) > check->titleChar && check->rightChild != NULL)
      {
        check = check->rightChild;
      }

      else if(title.at(0) < check->titleChar && check->leftChild != NULL)
      {
        check = check->leftChild;
      }
    }

    if(check == NULL)
    {
        cout << "Movie: " << title << " not found, cannot delete." << endl;
    }
}

///////////////////////////////////////////////////////////////////////////////
TreeNode* deleteNode(TreeNode *currNode)
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
        if(currNode->parent->leftChild == currNode)
        { 
          //cout << "2" << endl;
          currNode->parent->leftChild = currNode->rightChild;
          currNode->rightChild->parent = currNode->parent;
        }
        
        else if(currNode->parent->rightChild == currNode)
        {
          //cout << "3" << endl;
          currNode->parent->rightChild = currNode->rightChild;
          currNode->rightChild->parent = currNode->parent;
        }
        TreeNode *temp = currNode->rightChild;
        delete currNode;
        return temp;
    }
    //Only left child
    else if(currNode->rightChild == NULL && currNode->leftChild != NULL)
    {
        if(currNode->parent->leftChild == currNode)
        { 
          //cout << "2" << endl;
          currNode->parent->leftChild = currNode->leftChild;
          currNode->leftChild->parent = currNode->parent;
        }
        
        else if(currNode->parent->rightChild == currNode)
        {
          //cout << "3" << endl;
          currNode->parent->rightChild = currNode->leftChild;
          currNode->leftChild->parent = currNode->parent;
        }
        TreeNode *temp = currNode->leftChild;
        delete currNode;
        return temp;
    }
    //Both left and right child
    else
    {
      TreeNode *temp = getMinValueNode(currNode->rightChild);
      currNode->head = temp->head;
      currNode->titleChar = temp->titleChar;
      currNode->rightChild = deleteNode(currNode->rightChild);
      return temp;
    }
}
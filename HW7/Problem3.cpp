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
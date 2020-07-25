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
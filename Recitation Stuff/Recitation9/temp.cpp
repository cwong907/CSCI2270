void deleteN(TreeNode* temp) 
{
  if(temp->parent == NULL)
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
    LLMovieNode* del = temp->head;
    while (del != NULL)
    {
      delete del;
      del = del->next;
    }
    temp->head = NULL;
  }
  delete temp;
}



//10

vertex* n2 = n->adj[x].v;
            if(n2->visited == false)
            {
              n2->visited = true;
              n2->distance = n->distance + 1;
              n2->pred = n;
              q.push(n2);

              if(n2->key == dest)
                return n2->distance;
            }

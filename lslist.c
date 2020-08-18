#include<stdlib.h>
#include<string.h>
#include"lslist.h"

#include<stdio.h>
//Source file for our list structure.

list lcreate(size_t size_of_elements)
{
  list l;
  l.head = NULL;
  l.size_of_elements = size_of_elements;
  return l;
}

void ladd(list *l, void *data_to_add)
{
  //We need to iterate through the list to get to the end...
  if(l->head == NULL) //empty list...
  {
    l->head = malloc(l->size_of_elements);
    memcpy(l->head, data_to_add, l->size_of_elements);
  }
  else
  {
    lnode *temp = l->head;

    while(temp->next != NULL)
      temp = temp->next;

    temp->next = malloc(l->size_of_elements);
    memcpy(temp->next, data_to_add, l->size_of_elements);
  }
}

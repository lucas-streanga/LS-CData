#include<stdlib.h>
#include<string.h>
#include"lslist.h"

//Source file for our list structure.

list lcreate(size_t size_of_elements)
{
  list l;
  l.head = NULL;
  l.size_of_elements = size_of_elements;
  return l;
}

int lempty(list l)
{
  if(l.head == NULL)
    return 1;
  else
    return 0;
}

iterator lget(list *l)
{
  iterator it;
  it.l = l;
  it.current = l->head;
  return it;
}

void itnext(iterator *it)
{
  it->current = it->current->next;
}

void itreset(iterator *it)
{
  it->current = it->l->head;
}

void list_alloc(list *this_list, lnode **loc, void **data_to_add)
{
  *loc = malloc(sizeof(lnode));
  lnode n;
  n.next = NULL;
  n.data = malloc(this_list->size_of_elements);
  if(*loc != NULL && n.data != NULL)
  {
    **loc = n;
    memcpy((*loc)->data, *data_to_add, this_list->size_of_elements);
  }
}

void list_dealloc(lnode **loc)
{
  //We need to perfrom 2 frees...
  if(*loc != NULL && (*loc)->data != NULL)
  {
    free((*loc)->data);
    free(*loc);
    *loc = NULL;
  }
}

void ladd(list *l, void *data_to_add)
{
  //We need to iterate through the list to get to the end...
  if(l->head == NULL) //empty list...
  {
    list_alloc(l, &(l->head), &(data_to_add));
  }
  else
  {
    lnode *temp = l->head;

    while(temp->next != NULL)
      temp = temp->next;

    list_alloc(l, &(temp->next), &(data_to_add));
  }
}

void ladd_front(list *l, void *data_to_add)
{
  //We need to insert
  if(l->head == NULL)
  {
    list_alloc(l, &(l->head), &(data_to_add));
  }
  else
  {
    lnode *temp = l->head;
    list_alloc(l, &(l->head), &(data_to_add));
    l->head->next = temp; //relink the list.
  }
}

int lsize(list l)
{
  int count = 0;

  lnode *temp = l.head;
  while(temp != NULL)
  {
    temp = temp->next;
    count++;
  }
  return count;
}

void * lat(list *l, int index)
{
  if(index >= 0 && index < lsize(*l))
  {
    int cur_index = 0;
    lnode *temp = l->head;
    while(temp != NULL)
    {
      if(cur_index == index)
        return temp->data;

      temp = temp->next;
      cur_index++;
    }
  }
  return NULL;
}

void * lat_iterator(list * l, iterator it)
{
  if(it.current != NULL)
  {
    return (it.current->data);
  }
  return NULL;
}

void lremove(list *l, int index)
{
  if(index >= 0 && index < lsize(*l))
  {
    int cur_index = 0;
    lnode *temp = l->head;
    lnode *prev = l->head;
    if(index == 0)
    {
      lnode *temp = l->head->next;
      list_dealloc(&(l->head));
      l->head = temp;
      return;
    }
    while(temp != NULL)
    {
      if(cur_index == index)
      {
        prev->next = temp->next;
        list_dealloc(&temp);
        return;
      }

      if(temp != l->head)
        prev = prev->next;

      temp = temp->next;
      cur_index++;
    }
  }
}

void lfree(list *l)
{
  while(l->head != NULL)
  {
    lnode *temp = l->head->next;
    list_dealloc(&(l->head));
    l->head = temp;
  }
}

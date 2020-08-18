#ifndef _LSLIST_H
#define _LSLIST_H

#include<stdlib.h>

//Header file for the list structure...

typedef struct lnode
{
  void *data;
  struct lnode *next;
}
lnode;

typedef struct list
{
  lnode *head;
  size_t size_of_elements;
}
list;

//Prototypes

//lcreate - function used to create a list.
list lcreate(size_t);
//ladd - add data to the end of the list...
void ladd(list *, void *);

#endif

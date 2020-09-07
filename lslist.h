#ifndef _LSLIST_H
#define _LSLIST_H

#include<stdlib.h>

#define ITEND NULL

/*Header file for the list structure...*/

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

typedef struct iterator
{
  list *l; /*the list that corresponds to this iterator.*/
  lnode *current;
}
iterator;

/*Prototypes

/*lcreate - function used to create a list.*/
list lcreate(size_t);
/*lempty - find if list is empty*/
int lempty(list);
/*lget - returns an iterator for the list.*/
iterator lget(list *);
/*itnext - increment the iterator*/
void itnext(iterator *);
/*itreset - set current location to start*/
void itreset(iterator *);
/*list_alloc - function used internally for list allocation. Users shouldn't use this...*/
/*void list_alloc(list *, lnode **, void **);*/
/*list_dealloc - function used internally for list data deallocation. Users shouldn't use this...*/
/*void list_dealloc(lnode **);*/
/*ladd - add data to the end of the list...*/
void ladd(list *, void *);
/*ladd_front - add data to the front of the list*/
void ladd_front(list *, void *);
/*lsize - returns an int for the number of elements in the list*/
int lsize(list);
/*lat - returns a pointer to data in the list*/
void * lat(list *, int);
/*lat_iterator - returns a void pointer to data at the iterator.*/
void * lat_iterator(list *, iterator);
/*lremove - remove an element from the list*/
void lremove(list *, int);
/*lfree - free the entire linked list.*/
void lfree(list *);

#endif

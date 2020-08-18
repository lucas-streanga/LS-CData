#ifndef _LSVECTOR_H
#define _LSVECTOR_H

#include<stdlib.h>

#define VDEFAULT_MAX_SIZE 5;

//The main vector structure
typedef struct vector
{
  unsigned int cur_size; //Keep track of the current number of elements in the vector
  unsigned int max_size; //Max elements in the vector
  size_t size_of_elements; //Specific size for each element
  void *data; //Pointer to the actual data being stored.
} vector;

//Prototypes here...

//vcreate - function used to create vector
vector vcreate(size_t);
//vget - return a pointer to the vector data so we can use array notation
void * vget(vector);
//vadd - add some data to the back of the vector
void vadd(vector *, void *);
//vadd_front - same as vadd except for front
void vadd_front(vector *, void *);
//vsize - return the size of the vector
int vsize(vector);
//vremove - will attempt to remove an index from the array. Will return either 1 or 0 depending on if remove is successful
int vremove(vector *, int);
//vset - will attempt to change an element in the vector. Will return either 1 or 0 depending on if change is successful
int vset(vector *, int, void *);
//vat - will return a pointer to data at an index. NULL if invalid index.
void * vat(vector *, int);
//vfree - will deallocate the vector data
void vfree(vector *);

#endif

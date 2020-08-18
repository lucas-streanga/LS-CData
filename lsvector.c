#include<stdlib.h>
#include<string.h>
#include"lsvector.h"

vector vcreate(size_t size_of_elements)
{
  vector v;
  v.cur_size = 0;
  v.max_size = VDEFAULT_MAX_SIZE;
  v.size_of_elements = size_of_elements;
  //Initial alloc
  v.data = malloc(v.size_of_elements * v.max_size);
  return v;
}

void * vget(vector v)
{
  return v.data;
}

void vadd(vector *v, void * data_to_add)
{
  if(v->cur_size < v->max_size)
  {
    memcpy(v->data + (v->cur_size * v->size_of_elements), data_to_add, v->size_of_elements);
    v->cur_size++;
  }
  else
  {
    v->max_size = v->max_size << 1; //Double the size of our array...
    v->data = realloc(v->data, (v->max_size * v->size_of_elements));
    memcpy(v->data + (v->cur_size * v->size_of_elements), data_to_add, v->size_of_elements);
    v->cur_size++;
  }
}

void vadd_front(vector *v, void * data_to_add)
{
  if(v->cur_size < v->max_size) //No realloc is necessary
  {
    //Two memcpy are necessary - one to move the vector down and then one to add our new data...
    memcpy(v->data + (v->size_of_elements), v->data, v->size_of_elements * v->cur_size);
    memcpy(v->data, data_to_add, v->size_of_elements);
    v->cur_size++;
  }
  else //Must realloc...
  {
    v->max_size = v->max_size << 1; //Double the size of our array...
    v->data = realloc(v->data, (v->max_size * v->size_of_elements));
    memcpy(v->data + (v->size_of_elements), v->data, v->size_of_elements * v->cur_size);
    memcpy(v->data, data_to_add, v->size_of_elements);
    v->cur_size++;
  }
}

int vsize(vector v)
{
  return v.cur_size;
}

int vremove(vector *v, int index)
{
  //We need to do a memcpy to move everything to the left...
  if(index < v->cur_size && index >= 0)
  {
    memcpy(v->data + (index * v->size_of_elements), v->data + ((index + 1) * v->size_of_elements), v->size_of_elements * (v->cur_size - index - 1));
    v->cur_size--;
    return 1;
  }
  return 0;
}

int vset(vector *v, int index, void *data_to_add)
{
  if(index < v->cur_size && index >= 0)
  {
    memcpy(v->data + (index * v->size_of_elements), data_to_add, v->size_of_elements);
    return 1;
  }
  return 0;
}

void * vat(vector *v, int index)
{
  if(index < v->cur_size && index >= 0)
  {
    return (v->data + (index * v->size_of_elements));
  }

  return NULL;
}

void vfree(vector *v)
{
  free(v->data);
}

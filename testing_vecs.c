#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

typedef struct vector
{
  void * data;
  size_t size;
  size_t current;
  size_t size_of_elements;
}
vector;

void * funct_vat(vector *, size_t);

#define VEC_START_SIZE 4

#define vcreate(name, type) \
vector * vec ## name = malloc(sizeof(vector));\
vec ## name->data = malloc(VEC_START_SIZE * sizeof(type));\
type * name = (type *) vec ## name->data;\
vec ## name->size=VEC_START_SIZE;\
vec ## name->current = 0;\
vec ## name->size_of_elements = sizeof(type)\

#define vpush_back(name, dat) \
{ \
if(vec ## name->current >= vec ## name->size) \
{ \
  vec ## name->size = vec ## name->size * 2; \
  name = (__typeof__(name)) realloc(name, vec ## name->size * sizeof(vec ## name->size_of_elements));\
  vec ## name->data = (void *) name; \
} \
name[vec ## name->current] = dat;\
vec ## name->current++; \
} \

#define vsize(name) vec ## name->current

#define vempty(name) (!vec ## name->current)

#define vdelete(name) free(vec ## name->data); free(vec ## name)

void * funct_vat(vector * v, size_t index)
{
  if(index >= v->current)
  {
    printf("Out of bounds vector access in macro vat.\nThis can cause a segmentation fault.\n");
    printf("Vector max index: %llu\nIndex requested: %llu\n", v->current - 1, index);
    return v->data;
  }
  return v->data + (index * v->size_of_elements);
}

#define vat(name, index) *(__typeof__(name)) (funct_vat(vec ## name, index))

#define vcapacity(name) (vec ## name->size)

#define velement_size(name) (vec ## name->size_of_elements)

int main(void)
{
  vcreate(v, int);
  if(vempty(v))
    printf("V is empty\n");
  for(int i = 0; i < 1000; i++)
    vpush_back(v, i);
  for(int i = 0; i < vsize(v); i++)
    printf("%d\n", vat(v, i + 1));

  vcreate(v2, double);
  for(int i = 0; i < 10; i++)
    vpush_back(v2, i);
  for(int i = 0; i < vsize(v2); i++)
    printf("%lf\n", vat(v2, i));

  printf("Capacity of v1: %u\n", vcapacity(v));

  vdelete(v);
  vdelete(v2);

  return 0;
}

#include<stdio.h>
#include"lslist.h"
#include"lsvector.h"

int main(void)
{
  //Print the sizes.
  printf("Size of vector: %d\nSize of list: %d\n", sizeof(vector), sizeof(list));
  //Create a vector and list.
  vector v = vcreate(sizeof(int));
  list l = lcreate(sizeof(int));

  //For loop to test adding items to a list...
  int i;
  for(i = 1; i < 1000; i = i*2)
    ladd(&l, &i);

  return 0;
}

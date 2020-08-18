#include<stdio.h>
#include"lslist.h"
#include"lsvector.h"

int main(void)
{
  //Print the sizes.
  printf("Size of vector: %d\nSize of list: %d", sizeof(vector), sizeof(list));
  printf("\nSize of iterator: %d\n", sizeof(iterator));
  //Create a vector and list.
  vector v = vcreate(sizeof(int));
  list l = lcreate(sizeof(int));

  //For loop to test adding items to a list...
  int i;
  for(i = 1; i < 1000; i = i*2)
  {
    ladd(&l, &i);
    printf("%d ", i);
  }
  lremove(&l, 0);
  lremove(&l, 1);
	//Print out the first element in the list..
  iterator it = lget(l);
	for(it; it.current != ITEND; itnext(&it))
  {
    printf("\nAt interator: %d", *(int *)lat_iterator(&l, it));
  }
  for(i = 0; i < lsize(l); i++)
  {
    printf("\nAt index %d: %d", i, *(int *)lat(&l, i));
  }
  printf("\nSize of our list: %d\n", lsize(l));

  vfree(&v);
  lfree(&l);

  return 0;
}

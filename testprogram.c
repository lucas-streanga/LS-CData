#include<stdio.h>
#include"lslist.h"
#include"lsvector.h"
#include"lsstring.h"

int main(void)
{
  //Print the sizes.
  printf("Size of vector: %ld\nSize of list: %ld", sizeof(vector), sizeof(list));
  printf("\nSize of iterator: %ld\n", sizeof(iterator));
  printf("\nSize of string: %ld\n", sizeof(string));
  //Create a vector and list.
  vector v = vcreate(sizeof(int));
  list l = lcreate(sizeof(int));
  string s = screate("hello!!");
  sset(&s, "new string!!! This is a new string!!!");
  sset(&s, "hi there");
  sset(&s, "mmm whatcha say...");
  sset(&s, "hey hey hey hey hey hey");
  sadd(&s, "!!");
  sclear(&s);
  sadd_front(&s, "... ");
  //sset(&s, "ll");
  printf("%s", sget(&s));
  printf("\n%d", ssize(s));

  //For loop to test adding items to a list...
  int i;
  for(i = 1; i < 1000; i = i*2)
  {
    ladd(&l, &i);
    //printf("%d ", i);
  }
  for(i = 1; i < 1000; i++)
  {
    vadd(&v, &i);
    //printf("%d ", i);
  }

  lremove(&l, 0);
  lremove(&l, 1);
	//Print out the first element in the list..
  iterator it = lget(l);
	for(it; it.current != ITEND; itnext(&it))
  {
    //printf("\nAt interator: %d", *(int *)lat_iterator(&l, it));
  }
  for(i = 0; i < lsize(l); i++)
  {
    //printf("\nAt index %d: %d", i, *(int *)lat(&l, i));
  }
  for(i = 0; i < vsize(v); i++)
  {
    //printf("\nAt index %d: %d", i, *(int *)vat(&v, i));
  }
  printf("\nSize of our list: %d\n", lsize(l));

  vfree(&v);
  lfree(&l);
  sfree(&s);

  return 0;
}

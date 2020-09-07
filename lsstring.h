#ifndef _LSSTRING_H
#define _LSSTRING_H

#include<stdlib.h>

/*This define is used for small string optimization. Small string will not be heap allocated.*/
#define SMALL_STRING_SIZE 15

typedef union lsstring_allocation_unit
{
  char *data;
  char small_data[SMALL_STRING_SIZE + 1];
}
string_alloc_unit;

typedef struct lsstring
{
  unsigned int cur_size;
  unsigned int max_size;
  string_alloc_unit this_str;
}
strvec;

/*function to create a string vector.*/
strvec screate(char *);

const char * sget(strvec *);

void sset(strvec *, char *);

void sfree(strvec *);

int ssize(strvec);

void sadd(strvec *, char *);

void saddc(strvec *, char);

void sadd_front(strvec *, char *);

void saddc_front(strvec *, char);

void sclear(strvec *);

#endif

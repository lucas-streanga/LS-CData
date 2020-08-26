#include<stdlib.h>
#include<string.h>
#include"lsstring.h"
#include<stdio.h>

string screate(char *input)
{
  string s;
  s.cur_size = strlen(input);
  s.max_size = s.cur_size;
  if(s.max_size < SMALL_STRING_SIZE)
  {
    strcpy(s.this_str.small_data, input);
    return s;
  }
  else
  {
    s.this_str.data = malloc((s.max_size + 1) * sizeof(char));
    s.this_str.data = memcpy(s.this_str.data, input, s.cur_size + 1);
  }
  return s;
}

const char * sget(string *s)
{
  if(s->max_size < SMALL_STRING_SIZE)
    return s->this_str.small_data;
  else
    return s->this_str.data;

}

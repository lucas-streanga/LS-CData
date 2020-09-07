#include<stdlib.h>
#include<string.h>
#include"lsstring.h"
#include<stdio.h>

void string_alloc(strvec *s, char *input, unsigned int length_of_string)
{
  if(length_of_string <= s->max_size) /*No new allocations are necessary*/
  {
    if(s->max_size < SMALL_STRING_SIZE) /*This is a small string*/
    {
      strcpy(s->this_str.small_data, input);
      s->cur_size = length_of_string;
      return;
    }
    else /*This was not previously a small string, but could become one...*/
    {
      if(length_of_string >= SMALL_STRING_SIZE) /*must remain heap allocated*/
      {
        /*We need to do one more check
        /*If the new string is significantly smaller than the last,
        /*We will save space an realloc.
        /*Otherwise, we won't bother*/

        if(length_of_string < ((s->max_size) / 2))
        {
          void *new_alloc = realloc(s->this_str.data, length_of_string + 1);
          if(new_alloc != NULL)
          {
            s->this_str.data = new_alloc;
            strcpy(s->this_str.data, input);
            s->cur_size = length_of_string;
            s->max_size = length_of_string;
          }
          return;
        }
        else
        {
          strcpy(s->this_str.data, input);
          s->cur_size = length_of_string;
          return;
        }
      }
      else
      {
        free(s->this_str.data);
        strcpy(s->this_str.small_data, input);
        s->cur_size = length_of_string;
        s->max_size = length_of_string;
        return;
      }
    }
  }
  else /*Must do a reallocation/grow*/
  {
    /*printf("Length of string is not less than or equal to the old max %s", input);*/
    if(length_of_string < SMALL_STRING_SIZE) /*Still a small string even after growing...*/
    {
      strcpy(s->this_str.small_data, input);
      s->cur_size = length_of_string;
      s->max_size = length_of_string;
      return;
    }
    else /*No longer a small string. Must find out if it was a small string before*/
    {
      if(s->max_size < SMALL_STRING_SIZE) /*was previously a small string*/
      {
        s->this_str.data = malloc((length_of_string + 1) * sizeof(char));
        strcpy(s->this_str.data, input);
        s->cur_size = length_of_string;
        s->max_size = length_of_string;
        return;
      }
      else
      {
        void *new_alloc = realloc(s->this_str.data, length_of_string + 1);
        if(new_alloc != NULL)
        {
          s->this_str.data = new_alloc;
          strcpy(s->this_str.data, input);
          s->cur_size = length_of_string;
          s->max_size = length_of_string;
        }
        return;
      }
    }
  }
}

strvec screate(char *input)
{
  strvec s;
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

void sset(strvec *s, char *input)
{
  string_alloc(s, input, strlen(input));
}

const char * sget(strvec *s)
{
  if(s->max_size < SMALL_STRING_SIZE)
    return s->this_str.small_data;
  else
    return s->this_str.data;
}

int ssize(strvec s)
{
  return s.cur_size;
}

void sadd(strvec *s, char *str_to_add)
{
  /*We will have to create a temporary char *.*/
  char temp[strlen(sget(s)) + strlen(str_to_add) + 1];
  strcpy(temp, sget(s));
  strcpy(temp + strlen(sget(s)), str_to_add);
  string_alloc(s, temp, strlen(temp));
}

void saddc(strvec *s, char char_to_add)
{
  char temp[strlen(sget(s)) + 2]; /*Plus two for the null term and the new char*/
  strcpy(temp, sget(s));
  temp[strlen(sget(s)) - 1] = char_to_add;
  temp[strlen(sget(s))] = '\0';
  string_alloc(s, temp, strlen(temp));
}

void sadd_front(strvec *s, char *str_to_add)
{
  char temp[strlen(sget(s)) + strlen(str_to_add) + 1];
  strcpy(temp, str_to_add);
  strcpy(temp + strlen(str_to_add), sget(s));
  string_alloc(s, temp, strlen(temp));
}

void saddc_front(strvec *s, char char_to_add)
{
  char temp[strlen(sget(s)) + 2]; /*Plus two for the null term and the new char*/
  strcpy(temp + 1, sget(s)); /*leave room at the beginning for the new char.*/
  temp[0] = char_to_add;
  temp[strlen(sget(s))] = '\0';
  string_alloc(s, temp, strlen(temp));
}

void sclear(strvec *s)
{
  string_alloc(s, "", 0);
}

void sfree(strvec *s)
{
  if(s->max_size >= SMALL_STRING_SIZE && s->this_str.data != NULL)
    free(s->this_str.data);
}

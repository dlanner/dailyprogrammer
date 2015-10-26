#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Given a list of working keyboard keys,
// and a list of valid words,
// find the longest valid word that can be formed from the working key characters (don't have to use all keys)

// First word in valid_words is longest_word
// For word in valid_words:
//     if intersection of working_keys and word is not empty set, and word is longer than previous word:
//          word is new longest_word

int
get_num_lines_to_read()
{
  int num_lines_to_read;
  puts("How many lines to read?");
  scanf("%d", &num_lines_to_read);
  return num_lines_to_read;
}

void
get_working_keys(char* working_keys_buffer)
{
  memset(working_keys_buffer, 0, sizeof(working_keys_buffer));
  puts("What keys work?");
  scanf("%s", working_keys_buffer);
  printf("Your working keys are: %s\n", working_keys_buffer);
}

bool
word_is_typeable(char* word, char* working_keys)
{
  int i, j, match_count;
  for (i = 0; i < strlen(word); i++)
  {
    for (j = 0; j < strlen(working_keys); j++)
    {
      if (word[i] == working_keys[j])
      {
        match_count++;
      }
    }
  }
  return match_count == strlen(word);
}

int
main(int argc, char** argv)
{
  int num_lines_to_read = get_num_lines_to_read();
  char working_keys[128];
  int string_length;
  int i, j;

  int max_word_size = 60;
  char valid_word[max_word_size];
  char longest_word[max_word_size];
  memset(longest_word, 0, max_word_size);

  FILE * fp;
  fp = fopen("/usr/share/dict/words", "r");
  if (fp == NULL)
  {
    perror("Error opening file");
  }
  else
  {
    for (i = 0; i < num_lines_to_read; i++)
    {
      rewind(fp);

      get_working_keys(working_keys);

      while(fgets(valid_word, max_word_size, fp))
      {
        valid_word[strlen(valid_word)-1] = '\0';
        if (word_is_typeable(valid_word, working_keys))
        {
          if (strlen(valid_word) > strlen(longest_word))
          {
            memset(longest_word, 0, max_word_size);
            strcpy(longest_word, valid_word);
          }
        }
      }
      printf("Longest valid word with your working keys is: %s\n", longest_word);
      memset(longest_word, 0, max_word_size);
      if (ferror(fp))
      {
        exit(1);
      }
      else
      {
      }
    }
  }
}

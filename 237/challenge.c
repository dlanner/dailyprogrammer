#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* 
longest_word_for_keys(char* working_keys, char** valid_words)
{
  // Given a list of working keyboard keys,
  // and a list of valid words,
  // find the longest valid word that can be formed from the working key characters (don't have to use all keys)

  // First word in valid_words is longest_word
  // For word in valid_words:
  //     if intersection of working_keys and word is not empty set, and word is longer than previous word:
  //          word is new longes_word
}

void
get_num_lines_to_read(char* num_lines_to_read_buffer)
{
  puts("How many lines to read?");
  scanf("%d", &num_lines_to_read);
}

void
get_working_keys(char* working_keys_buffer)
{
  puts("What keys work?");
  scanf("%s", &working_keys);
  printf("Your working keys are: %s\n", working_keys);
}

char*
intersection(char* string1, char* string2)
{
  int i, j;
  int num_intersecting_chars = 0
  char intersecting_chars[128];
  for (i = 0; i < strlen(string1); i++)
  {
    for (j = 0; j < strlen(string2); j++)
    {
      if (strcasecmp(string1[i], string2[j] == 0)
      {
        intersecting_chars[num_intersecting_chars] = string1[i];
        num_intersecting_chars++;
      }
    }
  }
  return intersecting_chars;
}

int
main(int argc, char** argv)
{
  int num_lines_to_read;
  get_num_lines_to_read(num_lines_to_read);
  char working_keys[128];
  char intersecting_chars[128];
  int string_length;
  int i, j;

  int max_word_size = 60;
  char valid_word[max_word_size];
  int longest_word = "";

  FILE * fp;
  fp = fopen("/usr/share/dict/words", "r");

  for (i = 0; i < num_lines_to_read; i++)
  {
    rewind(fp);

    get_working_keys(working_keys);

    for (j = 0; j < 26; j++)
    {
    }

    if (fp == NULL)
    {
      perror("Error opening file");
    }
    else
    {
      while(fgets(valid_word, max_word_size, fp))
      {
        printf("Valid word: %s\n", valid_word);
        for (i = 0; i < strlen(valid_word); i++)
        {
          printf("Char: %c\n", valid_word[i]);
          for (j = 0; j < strlen(working_keys); j++)
          {
            intersecting_chars = intersection(valid_word[i], working_keys[j]);
            if (strlen(intersecting_chars) > 0 && strlen(valid_word) > strlen(longest_word))
            {
              longest_word = valid_word;
              printf("Got new longest word: %s\n", longest_word);
            }
          }
        }
      }
      if (ferror(fp))
      {
        exit(1);
      }
      else
      {
      }
    }
    printf("Longest valid word with your working keys is: %s\n", longest_word);
  }
}

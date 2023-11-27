/*

Disemvowel Trolls

*/

//mine solution:
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char *disemvowel(const char *str)
{
    const char *ptr = str;  //define another const char pointer to access to str;
    char c;
    int vowel_count = 0;

    // Count the number of vowels 
    while (c = *ptr++)
    {
        switch (tolower(c))
        {
            case 'a': //without break util case, it means every vowels captured, switch will go to the case 'u'
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                vowel_count++;
                break;
            default:
                break;
        }
    }
    //because you have to allocate the right memory space, so use original length - vowel_count + 1(for null terminator)
    // Allocate memory for the new string (original length - vowel count + 1 for null terminator)
    char *str_out = (char *)calloc(strlen(str) - vowel_count + 1, sizeof(char));
    char *out_ptr = str_out;

    // Copy non-vowel characters to the new string
    ptr = str;
    while (c = *ptr++)
    {
        switch (tolower(c))
        {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                break;
            default:
                *out_ptr++ = c;
                break;
        }
    }
    *out_ptr = '\0';

    return str_out;
}

//string.h
#include <string.h>
//strchr(const char *_Str,int _Val); can check if 
char *disemvowel(const char *s)
{
  char * ret = calloc(strlen(s) + 1, 1);
  for (char *q = ret; *s; s++) if (!strchr("aeiouAEIOU", *s)) *q++ = *s;
  return ret;
}
//but above wastes memory, below one is much better
char *disemvowel(const char *s)
{
  char * ret = calloc(strlen(s) + 1, 1);
  for (char *q = ret; *s; s++) if (!strchr("aeiouAEIOU", *s)) *q++ = *s;
  return realloc(ret, strlen(ret) + 1);
}
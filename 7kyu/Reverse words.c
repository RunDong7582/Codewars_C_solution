/*
Complete the function that accepts a string parameter, and reverses each word in the string. All spaces in the string should be retained.

Examples
"This is an example!" ==> "sihT si na !elpmaxe"
"double  spaces"      ==> "elbuod  secaps"
*/

//https://www.geeksforgeeks.org/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/

char* reverseWords(const char* text) {
  char *ret = calloc(strlen(text) + 1, sizeof(char)), *q = ret;
  int wordlen = 0;
  for (char *p = text; ; p++) {
    if (*p == ' ' || *p == '\0') {
      for (int i = 0; i < wordlen; i++) *q++ = *(p - 1 - i);
      if ((*q++ = *p) == '\0') break;
      wordlen = 0;
    } else wordlen++;
  }
  return ret;
}


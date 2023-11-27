//best solution
#include <string.h>
#include <stdlib.h>

char *repeat_str(size_t count, const char *src) {
  char *result = calloc(((count * strlen(src)) + 1), sizeof(char));
  while (count--)
    strcat(result, src); //directly connect it count times!
  return result;
}
// mine
#include <stdlib.h>
#include <string.h>
char *repeat_str(size_t count, const char *src)
{
  char *des;
// allocate a string on the heap
  des = (char * )calloc(count*strlen(src)+1 , sizeof(char));  // watch out the strlen doesn't count in '\0'
  if(src != NULL && des != NULL)
  {
     size_t k;
     for(k = 0; k < count * strlen(src); k++)
       des[k] = src[k%strlen(src)];
    // add NULL terminator at the end
    des[count * strlen(src)] = '\0';
  }
  
  return des;
}

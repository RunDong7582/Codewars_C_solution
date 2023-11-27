/*
Take 2 strings s1 and s2 including only letters from a to z. Return a new sorted string, the longest possible, containing distinct letters - each taken only once - coming from s1 or s2.

Examples:
a = "xyaabbbccccdefww"
b = "xxxxyyyyabklmopq"
longest(a, b) -> "abcdefklmopqwxy"

a = "abcdefghijklmnopqrstuvwxyz"
longest(a, a) -> "abcdefghijklmnopqrstuvwxyz"

*/
//mine:
#include <string.h>  
#include <stdlib.h>  
#include <stdio.h>  
  
char *longest(const char *s1, const char *s2) {  
    int c[26] = {0};  
    int cnt = 0;  
    int len1 = strlen(s1);  
    int len2 = strlen(s2);  
    int max_len = len1 > len2 ? len1 : len2;  
  
    for(int i = 0; i < len1; i++) {  
        int k = s1[i] - 'a';  
        if(!c[k]) {  
            c[k] = 1;  
            cnt++;  
        }  
    }  
    for(int j = 0; j < len2; j++) {  
        int k = s2[j] - 'a';  
        if(!c[k]) {  
            c[k] = 1;  
            cnt++;  
        }  
    }  
      
    char *result = malloc((cnt + 1) * sizeof(char));  // 分配存储结果字符串的内存  
    if (result == NULL) {  
        printf("Memory allocation failed\n");  
        return NULL;  
    }  
    int idx = 0;  
    for(int i = 0; i < 26; i++) {  
        if(c[i]) {  
            result[idx++] = 'a' + i;  // 将字母添加到结果字符串中  
        }  
    }  
    result[idx] = '\0';  // 在结果字符串的末尾添加空字符  
    // 对结果字符串进行排序（按照字母顺序）  
    qsort(result, cnt, sizeof(char), (int (*)(const void *, const void *))strcmp);  
    return result;  
}
//best practice:
char* longest(char* s1, char* s2) {
    char *result = calloc( 27, sizeof( char ) ) ;
    int n = 0;
    for ( char alpha = 'a'; alpha <= 'z'; alpha++ )
        if ( strchr( s1, alpha ) || strchr( s2, alpha ) )
            result[n++] = alpha;
    return result;
}

//
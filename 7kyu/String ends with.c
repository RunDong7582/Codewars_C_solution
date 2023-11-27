//String ends with?
#include <stdbool.h>  
#include <string.h>  
  
bool solution(const char *string, const char *ending)  
{  
    int _suffix = strlen(ending);  
    int n = strlen(string);  
      
    // 检查是否有足够的长度来容纳后缀  易错点1
    if (n < _suffix) {  
        return false;  
    }  
      
    // 移动 string 指针以便比较后缀   易错点2
    string += n - _suffix;  
      
    // 进行比较                      优化点1
    return strcmp(string, ending) == 0;  
}
//Lite version // Optimized version
bool solution(const char *string, const char *ending)
{
    int len = strlen(string) - strlen(ending);
    return len < 0 ?false :strcmp(string + len, ending) == 0;
}

//memcmp
bool solution(const char *string, const char *ending) {
    int str1 = strlen(string);
    int str2 = strlen(ending);
    
    return str1 >= str2 ? 0 == memcmp(&string[0 + str1 - str2], ending, str2) : false;
} 
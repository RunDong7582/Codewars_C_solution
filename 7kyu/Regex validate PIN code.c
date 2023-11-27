// ATM machines allow 4 or 6 digit PIN codes and PIN codes cannot contain anything but exactly 4 digits or exactly 6 digits.

// If the function is passed a valid PIN string, return true, else return false.
#include <stdbool.h>
#include <ctype.h>

bool validate_pin(const char *pin) {
  int count = 0;
  for(const char* p = pin; *p; p++){
    if(!isdigit(*p)) return false;
    count++;
  }
  if(count != 4 && count != 6) return false;
  return true;
}

// #include <stdbool.h>
// #include <string.h>

// bool validate_pin(const char *pin) {
  
//     size_t pin_len = strlen(pin);
//     char c = '\0';
//     if(pin_len == 4 || pin_len == 6)
//     {

//       while((c = *pin++))
//       {
//           if(c >= '0' && c <= '9')
//           {
//             continue;
//           }
//           else
//             break;
//       }
//       return (c == '\0'? true : false);
//     }
// }

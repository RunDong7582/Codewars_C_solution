#include <stdio.h>
void remove_exclamation_marks(const char *str_in, char *str_out);

int main() {
    const char *input = "Hello!! World!!!";
    char output[20];

    remove_exclamation_marks(input, output);

    printf("Result: %s\n", output);

    return 0;
}

void remove_exclamation_marks(const char *str_in, char *str_out) {
    int c;
    while (c = *str_in++) {
        if (c != '!') {
            *str_out++ = c;
        }
    }
    // Add null terminator at the end of the output string
    *str_out = '\0';

    //or  1 
    /*
     do
    {
     if (*str_in != '!') *str_out++ = *str_in;
     }
    while (*str_in++);
    */
    //or  2
    /*
       str_out[0] = '\0';
    for (int i = 0; i <= (int) strlen(str_in); i++) {
        if (str_in[i] == '!') continue;
    strncat(str_out, &str_in[i], 1);
     }
    */
 
}

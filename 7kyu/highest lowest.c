#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void FUNC(const char* strnum, char* result) {
    int highest = INT_MIN;
    int lowest = INT_MAX;
    int num;
    const char* ptr = strnum;

    while (*ptr != '\0') {
        // Skip leading spaces
        while (*ptr == ' ')
            ptr++;

        // Extract the number
        if (sscanf(ptr, "%d", &num) == 1) {
            // Update the highest and lowest values
            if (num > highest)
                highest = num;
            if (num < lowest)
                lowest = num;
            
            // Move the pointer to the next space or end of string
            while (*ptr != ' ' && *ptr != '\0')
                ptr++;
        }
        
        // Move past any remaining spaces
        while (*ptr == ' ')
            ptr++;
    }

    // Format the result string with the highest and lowest values
    sprintf(result, "%d %d", highest, lowest);
}

int main() {
    const char* strnum = "1 2 90 30 -666 666";
    
	char result[100];
	FUNC(strnum, result);
	printf("Result: %s\n", result);
	
	return 0;
}

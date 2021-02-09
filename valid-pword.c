#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

/*
In this example you have to validate if a user input string is alphanumeric. The given string is not nil/null/NULL/None, so you don't have to check that.

The string has the following conditions to be alphanumeric:

    At least one character ("" is not valid)
    Allowed characters are uppercase / lowercase latin letters and digits from 0 to 9
    No whitespaces / underscore
*/
const FIRST_INDEX = 0;
bool alphanumeric(const char* strin) {
    int i = 0;
    while((strin[i] != '\0' && isalnum(strin[i]))) {
        i++;
    }
    if((strin[i] == '\0' && strin[FIRST_INDEX] != '\0')) {
        return true;
    } else {
        return false;
    }
}

int main(int argc, char *argv) {
    printf("%d\n", true);
    printf("%d\n", alphanumeric("Hello_world"));
};



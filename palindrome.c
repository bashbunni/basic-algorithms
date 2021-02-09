#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

/**
 * A Palindrome reads the same backwards and forwards. 
 * 
*/
int palindrome(int i) {
    char str[60];
	sprintf(str, "%d", i);
	int len = strlen(str); // need to know the actual length of the string
	int r = len-1;
	for(int j = 0; j < len; j++)
	{
		if(str[j] != str[r])
		{
			printf("%d is not a palindrome\n", i);
			return -1;
		}
		r--;
	}
	printf("%d is a palindrome\n", i);
	return 0;
}

int main(int argc, char *argv) {

    palindrome(1234321); // true
    palindrome(12345678); // false
    palindrome(1111111); // true
}
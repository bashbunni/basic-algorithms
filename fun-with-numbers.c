/**
 * @author bashbunni
 * @version October 19 2019
 * 
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/*
 * Calculate the sum of digits in a given four digit integer iteratively
 * */
int sumofdigits_itr(int input)
{
    int sum = 0;
    for(double i = 1; i <= 4; i++)
    {
    	sum += ((input % (int)(pow(10, i))) / pow(10, i-1));
    }
    return sum;
}

/*
 * Calculate the sum of digits in a given four digit integer recursively
 * */
int sumofdigits_rec(int input)
{
	if(input == 0)
		return 0;
	return((input % 10) + sumofdigits_rec(input / 10));
}

/*
 * Display all prime numbers between two positive integers
 * */
void primes(int x, int y)
{
    for(int i = x; i <= y; i++)
    {
    	int flag = 1;
    	for(int j = 2; j <= i && i > 1; j++)
    	{
    		if (i % j == 0 && i != j)
    		{
    			flag = 0;
    		}
    	}
    	if(flag == 1)
    	{
    		printf("%d is a prime number\n", i);
    	}
    }
}

/*
 * Calculate the factorial of a number recursively
 * Note: this only supports numbers up to 12, otherwise the result becomes
 * too large to be contained as an unsigned int
 * */
unsigned int factorial_rec(unsigned int n)
{
	if(n == 0)
	{
		return 1;
	}
	return n * factorial_rec(n-1);
}

/*
 * Calculate the factorial of a number iteratively
 * Note: this only supports numbers up to 12, otherwise the result becomes
 * too large to be contained as an unsigned int
 * */
unsigned int factorial_itr(unsigned int n)
{
	int result = 1;
	while(n > 1)
	{
		result *= n;
		n--;
	}
	return result;
}

/* Display the frequency of each digit in a given integer
 * */
void freqdigits(int input)
{
	char str[60];
	char visited[60];
	sprintf(str, "%d", input);
	printf("Digit		Frequency\n--------	------------");
	for(int i = 0; str[i] != '\0'; i++)
	{
		int counter = 0;
		if(strchr(visited, str[i]) == '\0')
		{
			visited[i] = str[i];
			for(int j = 0; str[j] != '\0'; j++)
			{
				if(str[i] == str[j])
				{
					counter++;
				}
			}
		printf("\n%c		%d", str[i], counter);
		}
	}
}

int main(int argc, char* argv[])
{
	if(argc < 2)
	{
		printf("No command-line arguments provided.\nPlease try again with a command-line argument.");
		return EXIT_SUCCESS;
	}
	int arg1 = atoi(argv[1]);
	if(arg1 < 1000 || arg1 > 9999)
	{
		printf("Only positive, four digit integers are accepted input for the command-line argument.");
		return 0;
	}
	printf("Command line arg 1 is %d\n", arg1);
	printf("Exercise 1a) the sum of digits of %d is %d\n", arg1, sumofdigits_itr(arg1)); // outputs 10
    printf("Exercise 1b) the sum of digits of %d is %d\n", arg1, sumofdigits_rec(arg1)); // outputs 10
	printf("Exercise 2) => given a range of 24, 36\n");
    primes(24, 36);
	printf("Exercise 3a) the factorial of %d is %d\n", 5, factorial_rec(4));
	printf("Exercise 3b) the factorial of %d is %d\n", 9, factorial_itr(9));
    printf("The frequency of the digit %d is ", 1672167832437483974890);
    freqdigits(1672167832437483974890);
}

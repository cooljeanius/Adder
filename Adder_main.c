/*
 * Eric Gallager
 *
 * Problem/Assignment:
 *
 * I want you to add two numbers together, representing the numbers as integer arrays.
 * The basic idea is to use arrays to represent the numbers as digits and adding them much like one would add by hand. I want you to be able to type in the command line something like
 * (Adder 1234567890       987654321) and have something similar to "2222222211" as the output.
 *
 * I am willing to let you use the function below (void GetNumber(), that is). So you can have a main function starting with
 * main(int argc, char**argv)
 * then somewhere in your code you can say GetNumber(argv[1],MyFirstNumber); and you will have the proper input in MyFirstNumber.
 *
 * ---
 *
 * Plan:
 *
 * 1. Work building off of functions given
 *	1a. Fix errors
 * 2. ???
 *
 * Algorithm:
 *
 * 1. Get numbers for input from command line arguments (main() function)
 * 2. Put first number into integer array (GetNumber() function (provided by TA))
 * 3. Put second number into integer array (GetNumber() function again)
 * 4. Add the two arrays together
 * 5. Display output
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <getopt.h> // Might have an easier way to parse command-line arguments in it
#include <readline/readline.h> // Might have an easier way to parse command-line arguments in it
#include <string.h>
#define LENGTH 100 // Told to add by comment in copied code below

/* This function will take a string and give a number for that string, assuming that all of the string's characters are numeric.
 * This function is pass-by-reference, so you will need an array in main that will take the results of this array.
 * (This function was largely provided by the teaching assistant)
 */
int GetNumber(char Input[], int Number[]); // Function prototype
int
GetNumber(char Input[], int Number[]) // was originally "void GetNumber(char* Input,int Number[])" in TA's code
{
    int i = 0; // Initialize loop-counter for for-loop
	// printf("\n i = %i \n", i); // Statement for debugging
	int j = 0; // Initialize loop-counter for second while-loop
	// printf("\n j = %i \n", j); // Statement for debugging
    int Temp = 0; // Initialize number used to store numbers in in second while-loop
	// int length = LENGTH; // Convert from constant to variable
	// printf("\n length is %i \n", length); // Statement for debugging
	// printf("\n Number[i] is %i \n", Number[i]); // Statement for debugging (another place EXC_BAD_ACCESS errors can appear)
	Number[i] = 0; // Re-initialize, just in case
	// printf("\n Number[i] is %i \n", Number[i]); // Statement for debugging

	/* This following for-loop sets all of the elements of Number[] to zero.
	 * LENGTH was a define in my code; you can have lengths >= 100.
	 */
    for(i = 0; i < LENGTH; i++)
    {
        Number[i] = 0; // This can cause an EXC_BAD_ACCESS error, add a breakpoint (error seemed to disappear here (at first) when compiled without optimization, i.e. by using the -O0 compiler flag)
		// printf("\n Number[%i] is %i \n", i, Number[i]); // Statement for debugging
    }
	// printf("\n i = %i \n", i); // Statement for debugging
    i = 0; // originally was i = 0 in the teaching assistant's code, I changed to 1 to see if that would fix Input[i], then changed it back after that did nothing
	// printf("\n Number[i] is %i \n", Number[i]); // Statement for debugging
	// printf("\n i = %i \n", i); // Statement for debugging
	// printf("\n Initializing Number array to 0 done. \n"); // Statement for debugging

    /* This while-loop grabs every element in Input and places them in Number[] after subtracting 48
     * We're assuming that these are ASCII characters, which will give us the actual numbers after subtracting 48
     * To see more consult an ASCII character chart.
	 */
    while(Input[i]!='\0') // The previous EXC_BAD_ACCESS error crops back up here though, even when compiled unoptimized.
    {
        Number[i] = (int)Input[i]-48;
		// printf("\n Number[%i] = %i \n", i, Number[i]); // Statement for debugging
        i++;
    }
    j = 0; // Reset it, just in case
	int arglen = i; // Take whatever the loop counter got up to and store it
	// printf("\n arglen = %i \n", i); // Statement for debugging
	// printf("\n j = %i \n", j); // Statement for debugging
    i--; // I don't really know why this is here, but it was in the original code
	// printf("\n i = %i \n", i); // Statement for debugging
	// printf("\n Done entering input. \n"); // Statement for debugging

    /* The endianness of the numbers will be wrong right after inputing them.
	 * This while-loop simply does some flipping.
	 */
    while(i > j)
    {
        Temp=Number[i];
        Number[i]=Number[j];
        Number[j]=Temp;
		// printf("\n Number[%i] is %i \n", i, Number[i]); // Statement for debugging
        j++;
        i--;
    }
	// printf("\n Done flipping endianness. \n"); // Statement for debugging
	return arglen;
}

/*
 * Main: The main function
 */
int main(int argc, const char * argv[]) { // Convention for declaring main() from the C specification
	if (argc != 3) { // check to make sure number of arguments is correct
		printf("\n Incorrect number of arguments specified! This program can only add 2 numbers. \n"); // just in case
		printf(" Please try again. \n");
		exit(0); // end program
	} else {
		printf("\n You are adding _%i_ numbers. \n", argc-1);
		// printf("\n argc is %i \n", argc); // Statement for debugging (should be 3)
	}
	// printf("\n argv[0] is %s \n", argv[0]); // Statement for debugging
	// printf("\n argv[1] is %s \n", argv[1]); // Statement for debugging
	// printf("\n argv[2] is %s \n", argv[2]); // Statement for debugging
	int MyFirstNumber[LENGTH]; // Moved out of function paratmater list per advice found online, it should be an output array
	int j = 0; // Initialize loop-counter
	// printf("\n j is %i \n", j); // Statement for debugging
	for (j = 0; j < LENGTH; j++) // goes through each element of MyFirstNumber[]
	{
		MyFirstNumber[j] = 0; // sets each array element in MyFirstNumber[] to 0
		// printf("\n MyFirstNumber[%i] is %i \n", j, MyFirstNumber[j]); // Statement for debugging
	}
	// j = 0; // Reset j
	// printf("\n MyFirstNumber[j] is %i \n", MyFirstNumber[j]); // Statement for debugging
    int arglen1 = GetNumber((char*)argv[1], (int*)MyFirstNumber); // Originally this was copied from assignment, I've been messing with it though
    // printf("\n arglen1 = %i \n", arglen1); // Statement for debugging
	// printf("\n MyFirstNumber[j] is %i \n", MyFirstNumber[j]); // Statement for debugging
	int MySecondNumber[LENGTH]; // output array for second number
	for (j = 0; j < LENGTH; j++) // goes through each element of MySecondNumber[]
	{
		MySecondNumber[j] = 0; // sets each array element in MySecondNumber[] to 0
		// printf("\n MySecondNumber[%i] is %i \n", j, MySecondNumber[j]); // Statement for debugging
	}
	// j = 0; // Reset j
	int arglen2 = GetNumber((char*)argv[2], (int*)MySecondNumber); // Repeat what we just did with the first number with our second
	// printf("\n arglen2 = %i \n", arglen2); // Statement for debugging
	// printf("\n MySecondNumber[j] is %i \n", MySecondNumber[j]); // Statement for debugging
	printf("\n %s + %s = ", argv[1], argv[2]);
	int Answer[LENGTH];
	for (j = 0; j < LENGTH; j++) // Go through entire Answer array
	{
		Answer[j] = (MyFirstNumber[j] + MySecondNumber[j] + Answer[j]); // Add arrays together (Adding it to itself is just in case there's already something into it due to place value)
		if (Answer[j] >= 10) { // handle place-value
			Answer[j] = Answer[j] - 10; // You only ever carry a 1 when adding 2 numbers
			Answer[j+1]++; // Put into next digit
		}
	}
	j--; // Put j back down to the array size
	while (Answer[j] == 0) // Skip past all the 0s (with j-- below)
	{
		j--;
	}
	while (j >= 0) // Go through array backwards to print it (with j-- below)
	{
		printf("%i", Answer[j]);
		j--;
	}
	// j = 0; // Reset j
	// printf("\n j is %i \n", j); // Statement for debugging
	printf(" \n "); // I like putting extra whitespace in
    return 0;
}

// newline \n


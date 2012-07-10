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
 * Algorithm:
 *
 * 1. Work building off of functions given
 *	1a. Fix errors
 * 2. ???
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <getopt.h>
#include <readline/readline.h>
#include <string.h>
#define LENGTH 100 // Told to add by comment in copied code below

/* This function will take a string and give a number for that string, assuming that all of the string's characters are numeric.
 * This function is pass-by-reference, so you will need an array in main that will take the results of this array.
 * (This function was largely provided by the teaching assistant)
 */
void GetNumber(char Input[], int Number[]); // Function prototype
void
GetNumber(char Input[], int Number[]) // was originally "void GetNumber(char* Input,int Number[])" in TA's code
{
    int i = 0; // Initialize loop-counter for for-loop
	printf("\n i = %i \n", i); // Statement for debugging
	int j = 0; // Initialize loop-counter for second while-loop
	printf("\n j = %i \n", j); // Statement for debugging
    int Temp = 0; // Initialize number used to store numbers in in second while-loop
	int length = LENGTH; // Convert from constant to variable
	printf("\n length is %i \n", length); // Statement for debugging
	printf("\n Number[i] is %i \n", Number[i]); // Statement for debugging (another place EXC_BAD_ACCESS errors can appear)
	Number[i] = 0; // Re-initialize, just in case
	printf("\n Number[i] is %i \n", Number[i]); // Statement for debugging

	/* This following for-loop sets all of the elements of Number[] to zero.
	 * LENGTH was a define in my code; you can have lengths >= 100.
	 */
    for(i = 0; i < LENGTH; i++)
    {
        Number[i] = 0; // This can cause an EXC_BAD_ACCESS error, add a breakpoint (error seems to disappear here when compiled without optimization, i.e. by using the -O0 compiler flag)
		printf("\n Number[%i] is %i \n", i, Number[i]); // Statement for debugging
    }
	printf("\n i = %i \n", i); // Statement for debugging
    i = 0; // originally was i = 0 in the teaching assistant's code, I changed to 1 to see if that would fix Input[i], then changed it back after that did nothing
	printf("\n Number[i] is %i \n", Number[i]); // Statement for debugging
	printf("\n i = %i \n", i); // Statement for debugging
	printf("\n Initializing Number array to 0 done. \n"); // Statement for debugging
	Input[i] = 0; // This was originally put in to re-initialize Input[i] to try to stop the error from below from occurring, unfortunately it just causes the error to happen here now instead
	printf("\n Input[i] = %c", Input[i]); // Statement for debugging

    /* This while-loop grabs every element in Input and places them in Number[] after subtracting 48
     * We're assuming that these are ASCII characters, which will give us the actual numbers after subtracting 48
     * To see more consult an ASCII character chart.
	 */
    while(Input[i]!='\0') // The previous EXC_BAD_ACCESS error crops back up here though, even when compiled unoptimized.
    {
        Number[i] = (int)Input[i]-48;
        i++;
    }
    j = 0; // Reset it, just in case
	printf("\n j = %i \n", j); // Statement for debugging
    i--; // I don't really know why this is here, but it was in the original code
	printf("\n i = %i \n", i); // Statement for debugging
	printf("\n Done entering input. \n"); // Statement for debugging

    /* The endianness of the numbers will be wrong right after inputing them.
	 * This while-loop simply does some flipping.
	 */
    while(i > j)
    {
        Temp=Number[i];
        Number[i]=Number[j];
        Number[j]=Temp;
        j++;
        i--;
    }
	printf("\n Done flipping endianness. \n"); // Statement for debugging
}

/*
 * Main: The main function
 */
int main(int argc, const char * argv[]) { // Convention for declaring main() from the C specification
	if (argc != 3) { // check to make sure number of arguments is correct
		printf("\n Incorrect number of arguments specified! \n"); // just in case
	} else {
		printf("\n argc is %i \n", argc); // Statement for debugging (should be 3)
	}
	printf("\n This printf statement uses the placeholder \"%%s\": %s \n", "string"); // Testing using %s to print strings
	printf("\n First character of argv[0] is %c \n", *argv[0]); // Statement for debugging (Warning: %c can only display one character at a time. I'd use %s but that causes errors.)
	printf("\n First character of argv[1] is %c \n", *argv[1]); // Statement for debugging (Warning: %c can only display one character at a time. I'd use %s but that causes errors.)
	printf("\n First character of argv[2] is %c \n", *argv[2]); // Statement for debugging (Warning: %c can only display one character at a time. I'd use %s but that causes errors.)
	int *MyFirstNumber[LENGTH]; // Moved out of function paratmater list per advice found online, it should be an output array
	int j = 0; // Initialize loop-counter
	printf("\n j is %i \n", j); // Statement for debugging
	for (j = 0; j < LENGTH; j++) // goes through each element of MyFirstNumber[]
	{
		MyFirstNumber[j] = 0; // sets each array element in MyFirstNumber[] to 0
		printf("\n MyFirstNumber[%i] is %i \n", j, MyFirstNumber[j]); // Statement for debugging (this might give a compiler warning, but that's better than a runtime error for a simple print function)
	}
	j = 0; // Reset j
	printf("\n MyFirstNumber[j] is %i \n", MyFirstNumber[j]); // Statement for debugging (this might give a compiler warning, but that's better than a runtime error for a simple print function)
    GetNumber((char*)argv[1], /*(int*)*/MyFirstNumber[j]); // Originally this was copied from assignment, I've been messing with it though
    printf("\n MyFirstNumber[j] is %i \n", MyFirstNumber[j]); // Statement for debugging (clang's static analyzer said at one point that this is a dereference of a null pointer, but I haven't managed to get my program to run this far in the first place, so it's a moot point)
	printf("\n argc is %i \n", argc); // Statement for debugging
    return 0;
}

// newline \n


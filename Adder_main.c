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
 * 2. ???
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <getopt.h>
#include <readline/readline.h>
#define LENGTH 100 // Told to add by comment in copied code below

// This function will take a string and give a number for that string, assuming that all of the string's characters are numeric.
// This function is pass-by-reference, so you will need an array in main that will take the results of this array.
// (This function was largely provided by the teaching assistant)
void GetNumber(char Input[], int Number[]); // Function prototype
void 
GetNumber(char Input[], int Number[LENGTH]) // was originally "void GetNumber(char* Input,int Number[])" in TA's code
{
    int i = 0;
	int j = 0;
    int Temp = 0;
	int length = LENGTH; // Convert from constant to variable
	printf("\n Number[i] is %i \n", Number[i]); // Statement for debugging
	printf("\n i = %i \n", i); // Statement for debugging
	printf("\n j = %i \n", j); // Statement for debugging
	printf("\n length is %i \n", length); // Statement for debugging
	Number[i] = 0;
	printf("\n Number[i] is %i \n", Number[i]); // Statement for debugging
    // This loop sets all of the elements of Number[] to zero. LENGTH was a define in my code; you can have lengths >= 100
    for(i = 0; i < LENGTH; i++)
    {
        Number[i] = 0; // This can cause an EXC_BAD_ACCESS error, add a breakpoint (error seems to disappear here when compiled without optimization, i.e. by using the -O0 compiler flag)
    }
	printf("\n i = %i \n", i); // Statement for debugging
    i = 0; // originally was i = 0 in the teaching assistant's code, I changed to 1 to see if that would fix Input[i], then changed it back after that did nothing
	printf("\n Number[i] is %i \n", Number[i]); // Statement for debugging
	printf("\n i = %i \n", i); // Statement for debugging
	printf("\n Initializing Number array to 0 done. \n"); // Statement for debugging
	Input[i] = 0; // This was originally put in to re-initialize Input[i] to try to stop the error from below from occurring, unfortunately it just causes the error to happen here now instead
	printf("\n Input[i] = %c", Input[i]); // Statement for debugging
    // This loop grabs every element in Input and places them in Number[] after subtracting 48
    // We're assuming that these are ASCII characters, which will give us the actual numbers after subtracting 48
    // To see more consult an ASCII character chart.
    while(Input[i]!='\0') // The previous EXC_BAD_ACCESS error crops back up here though, even when compiled unoptimized.
    {
        Number[i] = (int)Input[i]-48;
        i++;
    }
    j = 0;
	printf("\n j = %i \n", j); // Statement for debugging
    i--;
	printf("\n i = %i \n", i); // Statement for debugging
	printf("\n Done entering input. \n"); // Statement for debugging
    // The endianness of the numbers will be wrong right after inputing them. This simply does some flipping.
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
int main(int argc, const char * argv[]) {
	int *MyFirstNumber[] = {0}; // Moved out of function paratmater list per advice found online
	// int i = LENGTH;
	int j = 0;
	// int OutputArray[] = {0}; // Needed to take output of GetNumber function
	// printf("\n Enter a number> "); // Prompt (placeholder)
	// scanf("%i", &MyFirstNumber[j]); // Get input, placeholder until I figure out how to pass command line arguments to a program from Xcode 3.2.6
	printf("\n argv is %c \n", **argv); // Statement for debugging
	printf("\n argc is %i \n", argc); // Statement for debugging
	// printf("\n MyFirstNumber is %i \n", MyFirstNumber[j]); // Statement for debugging
    GetNumber((char*)argv[1], /*(int*)*/MyFirstNumber[j]); // Originally this was copied from assignment
    printf("\n MyFirstNumber is %i \n", *MyFirstNumber[j]); // Statement for debugging (clang's static analyzer says this is a dereference of a null pointer, but I haven't managed to get my program to run this far in the first place, so it's a moot point)
	printf("\n argc is %i \n", argc); // Statement for debugging
    return 0;
}

// newline \n


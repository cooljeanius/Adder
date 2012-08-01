/*
 *  libgetnumber.c
 *  Adder
 *
 *  Created by Eric Gallager on 8/1/12.
 *  Copyright 2012 George Washington University. All rights reserved.
 *
 */

#include "libgetnumber.h"

/* 
 * This function will take a string and give a number for that string, assuming that all of the string's characters are numeric.
 * This function is pass-by-reference, so you will need an array in main that will take the results of this array.
 * It also returns the length of the number.
 */
int GetNumber(char Input[], int Number[]); // Function prototype
int
GetNumber(char Input[], int Number[]) // was originally "void GetNumber(char* Input,int Number[])" in TA's code
{
    int i = 0; // Initialize loop-counter for for-loop
	int j = 0; // Initialize loop-counter for second while-loop
    int Temp = 0; // Initialize number used to store numbers in in second while-loop
	Number[i] = 0; // Re-initialize, just in case
	
	/* This following for-loop sets all of the elements of Number[] to zero.
	 * LENGTH was a define in my code; you can have lengths >= 100.
	 */
    for(i = 0; i < LENGTH; i++)
    {
        Number[i] = 0; // This can cause an EXC_BAD_ACCESS error, add a breakpoint (error seemed to disappear here (at first) when compiled without optimization, i.e. by using the -O0 compiler flag)
    }
    i = 0; // originally was i = 0 in the teaching assistant's code, I changed to 1 to see if that would fix Input[i], then changed it back after that did nothing
	
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
	int arglen = i; // Take whatever the loop counter got up to and store it
	i--; // I don't really know why this is here, but it was in the original code
		
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
	// printf("\n Done flipping endianness. \n"); // Statement for debugging
	return arglen; // Pass the number's length back to main function
}

// newline \n


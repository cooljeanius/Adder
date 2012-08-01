/*
 *  Adder_linked.c
 *  Adder
 *
 *  Created by Eric Gallager on 8/1/12.
 *  Copyright 2012 George Washington University. All rights reserved.
 *
 *	Pretty much the same as Adder_main.c, except the GetNumber() function is linked from a library instead of built in.
 *
 */

#include "libgetnumber.h" // contains GetNumber() function

/*
 * Main: The main function
 */
int main(int argc, const char * argv[]) { // Convention for declaring main() from the C specification
	if (argc != 3) { // check to make sure number of arguments is correct
		printf("\n Incorrect number of arguments specified! This program can only add 2 numbers. \n"); // just in case
		printf(" Please try again. \n");
		exit(0); // end program, with 0 because even though this is a failure, it isn't an error though.
	} else {
		printf("\n You are adding _%i_ numbers. \n", argc-1);
	}
	int MyFirstNumber[LENGTH]; // Moved out of function paratmater list per advice found online, it should be an output array
	int j = 0; // Initialize loop-counter
	for (j = 0; j < LENGTH; j++) // goes through each element of MyFirstNumber[]
	{
		MyFirstNumber[j] = 0; // sets each array element in MyFirstNumber[] to 0
		// printf("\n MyFirstNumber[%i] is %i \n", j, MyFirstNumber[j]); // Statement for debugging
	}
    int arglen1 = GetNumber((char*)argv[1], (int*)MyFirstNumber); // Originally this was copied from assignment, I've been messing with it though
	int MySecondNumber[LENGTH]; // output array for second number
	for (j = 0; j < LENGTH; j++) // goes through each element of MySecondNumber[]
	{
		MySecondNumber[j] = 0; // sets each array element in MySecondNumber[] to 0
	}
	int arglen2 = GetNumber((char*)argv[2], (int*)MySecondNumber); // Repeat what we just did with the first number with our second
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
	printf(" \n "); // I like putting extra whitespace in
    return 0;
}

// newline \n


/*
 *  adder_with_example_code_from_textbook.c
 *  Adder
 *
 *  Created by Eric Gallager.
 *
 *	This file attempts to solve the same problem as Adder_main.c does, except it uses example code from the textbook (C Program Design for Engineers) instead of the example code supplied by our TA
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <getopt.h>
#include <readline/readline.h>
#include <string.h>

/*
 * add_arrays(): Adds correspondinding elements of arrays ar1 and ar2, storing the result in arsum.
 * Processes the first n elements only.
 */
void add_arrays (const double ar1[], const double ar2[], double arsum[], int n); // Prototype
void
add_arrays (const double	ar1[],		/* input -													*/
			const double	ar2[],		/*	arrays being added										*/
			double			arsum[],	/* output - sum of corresponding elements of ar1 and ar2	*/
			int				n)			/* input - number of element pairs summed					*/
{
	int i = 0; // Initialize
	printf("\n i = %i \n", i); // Statement for debugging
	printf("\n n = %i \n", n); // Statement for debugging
	/* Adds corresponding elements of ar1 and ar2 */
	for	(i = 0; i < n; ++i) {
		arsum[i] = ar1[i] + ar2[i];
		printf("\n arsum[i] = %.2f \n", arsum[i]); // Statement for debugging
	}
}

int main (int argc, const char * argv[]) {
	int i = 0; // Initialize loop-counter
	int x[5] = {0, 0, 0, 0, 0}; // Initialize array
	int y[5] = {0, 0, 0, 0, 0}; // Initialize array
	int x_plus_y[5] = {0, 0, 0, 0, 0}; // Initialize array
	printf("\n"); // I like adding pointless whitespace buffering around my text
	for (i = 0; i < 5; i++) // Goes through each element of x[]
	{
		printf("\n x[%i] is %i \n", i, x[i]); // Prints each entry in x[]
	}
	i = 0; // reset
	printf("\n i = %i \n", i); // Statement for debugging
	for (i = 0; i < 5; i++) // Goes through each element of y[]
	{
		printf("\n y[%i] is %i \n", i, y[i]); // Prints each entry in y[]
	}
	i = 0; // reset
	printf("\n i = %i \n", i); // Statement for debugging
	for (i = 0; i < 5; i++) // Goes through each element of x_plus_y[]
	{
		printf("\n x_plus_y[%i] is %i \n", i, x_plus_y[i]); // Prints each entry in x_plus_y[]
	}
	i = 0; // reset
	printf("\n i = %i \n", i); // Statement for debugging
	if (argc != 3) { // check to make sure number of arguments is correct
		printf("\n Incorrect number of arguments specified! \n"); // just in case
	} else {
		printf("\n argc is %i \n", argc); // Statement for debugging (should be 3)
	}
	for (i = 0; i < argc; i++) // Goes through each element of argv[]
	{
		printf("\n First character of *argv[%i] is %c \n", i, *argv[i]); // Prints each entry in argv[] (Warning: %c can only display one character at a time. I'd use %s but that causes errors.)
	}
	add_arrays(x, y, x_plus_y, 5); // taken from book (don't worry about any warnings about an incompatible pointer type, it still works)
	printf("\n arsum \n"); // Placeholder
	return 0;
}

// newline \n


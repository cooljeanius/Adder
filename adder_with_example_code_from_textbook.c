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
	int x[5] = {0, 0, 0, 0, 0}; // Initialize
	int y[5] = {0, 0, 0, 0, 0}; // Initialize
	int x_plus_y[5] = {0, 0, 0, 0, 0}; // Initialize
	printf("\n"); // Pointless
	printf("\n x[1] = %i \n", x[1]); // Statement for debugging
	printf("\n y[1] = %i \n", y[1]); // Statement for debugging
	printf("\n x_plus_y[1] = %i \n", x_plus_y[1]); // Statement for debugging
	printf("\n argc = %i \n", argc); // Statement for debugging
	printf("\n *argv[0] = %c \n", *argv[0]); // Statement for debugging
	add_arrays(x, y, x_plus_y, 5); // taken from book
	printf("\n arsum \n"); // Placeholder
	return 0;
}

// newline \n


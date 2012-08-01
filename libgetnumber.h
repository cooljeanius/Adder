/*
 *  libgetnumber.h
 *  Adder
 *
 *  Created by Eric Gallager on 8/1/12.
 *  Copyright 2012 George Washington University. All rights reserved.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <getopt.h> // Might have an easier way to parse command-line arguments in it
#include <readline/readline.h> // Might have an easier way to parse command-line arguments in it
#include <string.h>
#define LENGTH 100 // Told to add by comment in copied code below

/* 
 * This function will take a string and give a number for that string, assuming that all of the string's characters are numeric.
 * This function is pass-by-reference, so you will need an array in main that will take the results of this array.
 * It also returns the length of the number.
 */
extern int GetNumber(char Input[], int Number[]); // Function prototype

//newline \n


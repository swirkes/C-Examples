/**
 * generate.c
 *
 * Generates pseudorandom numbers in [0,MAX), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
 
#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// upper limit on range of integers that can be generated
#define LIMIT 65536

int main(int argc, string argv[])
{
    //Ensure that the user inputs a total of 2 or 3
    //arguments including the file name when running program
    if (argc != 2 && argc != 3)
    {
        printf("Usage: ./generate n [s]\n");
        return 1;
    }

    //Convert argument 1 to an interger
    //arg 0 is the file name
    int n = atoi(argv[1]);

    //If there are 3 total arguments from the user,
    //the third argument is converted to a long and 
    //used as the seed for a random number using
    //srand48. If no 3rd argument is provided, it uses
    //time(NULL) as the seed.
    if (argc == 3)
    {
        srand48((long) atoi(argv[2]));
    }
    else
    {
        srand48((long) time(NULL));
    }

    //Generate n numbers by getting the int value
    //of drand48 * the Limit to keep them under the 
    //specified range
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}

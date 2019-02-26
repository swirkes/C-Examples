#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    //check that an argument is supplied
    //if not, print the correct usage
    while (argc != 2)
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }
    //store string as int for cipher key
    //keep key between 0 and 26
    int k = atoi(argv[1]);
    k = k%26;
    //prompt for text to be enciphered and
    //store as string s
    printf("plaintext: ");
    string s = get_string();
    //iterate over every letter in plaintext
    for(int i = 0, n = strlen(s); i < n; i++)
    {
        //store the int value of the char
        int p = (int)s[i];
        //if char is uppercase, add the key value 
        //and subtract 26 if it is over 90 (to keep it alphabetic 
        //and in the right case)
        if(isupper(s[i]))
        {
            p = p + k;
            if (p > 90)
            {
                s[i] = p - 26;
            } else 
            {
                s[i] = p;
            }
        } 
        //if char is lowercase, add the key value
        //and subtract 26 if it is over 122 (to keep it alphabetic 
        //and case sensetive)
        if (islower(s[i]))
        {
            p = p + k;
            if (p > 122)
            {
                s[i] = p - 26;
            } else
            {
                s[i] = p;
            }
        }
    }
    //print new string as "ciphertext"
    printf("ciphertext: %s\n", s);
    return 0;
}
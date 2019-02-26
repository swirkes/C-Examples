#include <stdio.h>
#include <cs50.h>

long long getDigit (long long modulo, long long divisor, long long ccNumber)
{
    long long i = ((ccNumber%modulo)/divisor);
    if (i >= 5)
    {
        i = i * 2;
        i = (i%10) + (i/10);
    } else
    {
        i = i * 2;
    }
    return i;
}

long long getRemainingDigit (long long modulo, long long divisor, long long ccNumber)
{
    long long i = ((ccNumber%modulo)/divisor);
    return i;
}

int main(void){
    //declare long long for credit card input
    long long cardNumber;
    //ask for input from user. Check to make sure 
    //number is between 13 and 16 digits and is positive.
    do{         
    printf("Number: "); 
    cardNumber = get_long_long();
    }
    while (cardNumber <= 999999999 || cardNumber >= 10000000000000000);
    //determine the number of digits in the number.
    long long n = cardNumber;
    int digitCount = 0;
    while (n != 0){
        n /= 10;
        digitCount++;
    }

    long long a, b, c, d, e, f, g, h, a1, b1, c1, d1, e1, f1, g1, h1;
    
    a = getDigit(100, 10, cardNumber);
    b = getDigit(10000,1000, cardNumber);
    c = getDigit(1000000,100000, cardNumber);
    d = getDigit(100000000,10000000, cardNumber);
    e = getDigit(10000000000,1000000000, cardNumber);
    f = getDigit(1000000000000,100000000000, cardNumber);
    g = getDigit(100000000000000,10000000000000, cardNumber);
    h = getDigit(10000000000000000,1000000000000000, cardNumber);
            
    a1 = getRemainingDigit(10, 1, cardNumber);
    b1 = getRemainingDigit(1000,100, cardNumber);
    c1 = getRemainingDigit(100000,10000, cardNumber);
    d1 = getRemainingDigit(10000000,1000000, cardNumber);
    e1 = getRemainingDigit(1000000000,100000000, cardNumber);
    f1 = getRemainingDigit(100000000000,10000000000, cardNumber);
    g1 = getRemainingDigit(10000000000000,1000000000000, cardNumber);
    h1 = getRemainingDigit(1000000000000000,100000000000000, cardNumber);
            
    long long total = a + b + c + d + e + f + g + h + a1 + b1 + c1 + d1 + e1 + f1 + g1 + h1;
            
    if (total%10 == 0)
        {
            if (digitCount == 15 && (cardNumber/10000000000000 == 34 || cardNumber/10000000000000 == 37))
            {
                printf("AMEX\n");
            } else if (digitCount == 16 && (cardNumber/100000000000000 >= 51 && cardNumber/100000000000000 <= 55))
            {   printf("MASTERCARD\n");
            } else if (cardNumber/1000000000000 == 4 || cardNumber/1000000000000000 == 4)
            {
                 printf("VISA\n");
            } else
            {
                 printf("INVALID\n");
            }
        } else
        {
            printf("INVALID\n");
        }
    return 0;
}
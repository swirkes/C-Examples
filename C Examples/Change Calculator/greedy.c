#include <stdio.h>
#include <cs50.h>
#include <math.h>
int main(void){
    float x;
    do
    {
        printf("O hai! How much change is owed?\n");
        x = get_float();
    }
    while (x < 0.0);
    int change = round(x * 100);
    int coins = 0;
    while (change >= 100){
        coins = (change/100)*4;
        change = change%100;
    }
    while (change >= 25){
        coins++;
        change = change - 25;
    }
    while (change >= 10){
        coins++;
        change = change - 10;
    }
    while (change >= 5){
        coins++;
        change = change - 5;
    }
    while (change >= 1){
        coins++;
        change = change - 1;
    }
    printf("%i\n", coins);
    return 0;
}
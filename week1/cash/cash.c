#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float cash;
    int cnt = 0;
    do
    {
        cash = get_float("Change owed: ");
    }
    while (cash < 0.0099);
    cash = round(cash * 100);
    while (cash >= 25)
    {
        cnt++;
        cash -= 25;
    }
    while (cash >= 10)
    {
        cnt++;
        cash -= 10;
    }
    while (cash >= 5)
    {
        cnt++;
        cash -= 5;
    }
    while (cash > 0)
    {
        cnt++;
        cash -= 1;
    }
    printf("%d\n", cnt);
    return (0);
}
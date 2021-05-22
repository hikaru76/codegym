#include <cs50.h>
#include <stdio.h>

int check_number(long number)
{
    if ((number >= 100000000000000 && number <= 999999999999999) && (number / 10000000000000 == 34 || number / 10000000000000 == 37))
    {
        return (1);
    }
    else if ((number >= 1000000000000000 && number <= 9999999999999999) && \
    (number / 100000000000000 == 51 || number / 100000000000000 == 52 || \
    number / 100000000000000 == 53 || number / 100000000000000 == 54 || number / 100000000000000 == 55))
    {
        return (2);
    }
    else if ((number >= 1000000000000 && number <= 9999999999999 && number / 1000000000000 == 4) || \
    (number >= 1000000000000000 && number <= 9999999999999999 && number / 1000000000000000 == 4))
    {
        return (3);
    }
    return (0);
}

int main(void)
{
    long number = 0;
    long digits = 1;
    int digitscnt = 0;
    long tmp = number;
    int sum = 0;
    do
    {
        number = get_long("Number: ");
    }
    while (number < 1000000000);
    tmp = number;
    while (tmp)
    {
        digits *= 10;
        digitscnt += 1;
        tmp /= 10;
    }
    // printf("digits:%ld digitscnt:%d\n", digits, digitscnt);
    digits /= 10;
    while (digitscnt)
    {
        tmp = (number / digits) % 10;
        // printf("tmp:%ld\n", tmp);
        if (digitscnt % 2 == 1)
        {
            sum += tmp;
        }
        else
        {
            tmp *= 2;
            if (!(tmp / 10))
            {
                sum += tmp;
            }
            else
            {
                sum += tmp / 10 + tmp % 10;
            }
        }
        // printf("sum:%d\n", sum);
        digitscnt -= 1;
        digits /= 10;
    }
    // printf("sum:%d\n", sum);
    if (sum % 10 == 0)
    {
        if (check_number(number) == 1)
        {
            printf("AMEX\n");
        }
        else if (check_number(number) == 2)
        {
            printf("MASTERCARD\n");
        }
        else if (check_number(number) == 3)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
    return (0);
}
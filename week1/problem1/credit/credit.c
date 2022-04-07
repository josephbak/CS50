#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int getLength(long n);
int getLeadingNum(long n, int i);
int luhnAlgo(long n);

int main(void)
{
    // get a long integer.
    long number = get_long("Number: ");

    if (luhnAlgo(number) == 0)
    {
        printf("INVALID\n");
    }
    else
    {
        // Visa
        if (getLength(number) == 13)
        {
            if (getLeadingNum(number, 1) == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        // Amex
        else if (getLength(number) == 15)
        {
            if (getLeadingNum(number, 2) == 34 || getLeadingNum(number, 2) == 37)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        // Master or Visa
        else if (getLength(number) == 16)
        {
            if (getLeadingNum(number, 1) == 4)
            {
                printf("VISA\n");
            }
            else if (getLeadingNum(number, 2) == 51 || getLeadingNum(number, 2) == 52 || getLeadingNum(number, 2) == 53
                     || getLeadingNum(number, 2) == 54 || getLeadingNum(number, 2) == 55)
            {
                printf("MASTERCARD\n");
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
    }
}

int getLength(long n)
{
    return (int) floor(log10(labs(n))) + 1;
}

int getLeadingNum(long n, int i)
{
    int length = getLength(n);
    //printf("%li\n", (long) pow(10, length - 1));
    return n / (long) pow(10, length - i);
}

int luhnAlgo(long n)
{
    int length = getLength(n);
    long sum = 0;
    for (int i = 0; i < length; i++)
    {
        if (i % 2 == 0)
        {
            sum += (long)(n % (long) pow(10, i + 1)) / (long) pow(10, i);
        }
        else
        {
            long multiplied_num = (long) 2 * floor((long)(n % (long) pow(10, i + 1)) / (long) pow(10, i));
            //printf("%li: ", (long) (n % (long) pow(10, i+1)) / (long) pow(10, i));
            //printf("%li: ", multiplied_num);
            //printf("%li\n", (long) multiplied_num % 10);
            if (multiplied_num > 9)
            {
                sum = sum + 1 + (int)(multiplied_num % 10);
            }
            else
            {
                sum += multiplied_num;
            }
        }
    }
    //printf("%li\n", sum);
    if (sum % 10 == 0)
    {
        return 1;
    }
    return 0;
}
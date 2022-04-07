#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    for (int i = height; i > 0; i--)
    {
        for (int j = i - 1; j > 0; j--)
        {
            printf(" ");
        }

        for (int k = 0; k < height - i + 1 ; k++)
        {
            printf("#");
        }

        printf("  ");

        for (int k = 0; k < height - i + 1 ; k++)
        {
            printf("#");
        }

        // for(int j = i-1; j > 0; j--) {
        //     printf(" ");
        // }
        printf("\n");

    }
}
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>



string cipher(string key, string plaintext);

int main(int argc, string argv[])
{
    string key = argv[1];
    // if the key is not provided.
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // if the length of key is not 26
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // if the key contains non-alphabet letter
    int flag_alphabet = 0;
    for (int i = 0; i < 26; i++)
    {
        if ((int) key[i] < 65 || ((int) key[i] > 90 && (int) key[i] < 97) || (int) key[i] > 122)
        {
            flag_alphabet = 1;
        }
    }
    if (flag_alphabet == 1)
    {
        printf("Key contatins non alphabetic character.\n");
        return 1;
    }

    // if the key contains unique alphabets
    int flag_repeat = 0;
    for (int i = 0; i < 26; i++)
    {
        for (int j = i + 1; j < 26; j++)
        {
            if ((int) tolower(key[i]) == (int) tolower(key[j]))
            {
                flag_repeat = 1;
            }
        }
    }
    if (flag_repeat == 1)
    {
        printf("Key contatins repeated alphabet characters.\n");
        return 1;
    }

    string plaintext = get_string("plaintext: ");
    string ciphertext = cipher(key, plaintext);
    printf("ciphertext: %s", ciphertext);
    printf("\n");
    return 0;


}

string cipher(string key, string plaintext)
{
    string ciphertext = malloc(strlen(plaintext) + 1);
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        // alphabets
        if (isalpha(plaintext[i]) != 0)
        {
            // if lowercase
            if (islower(plaintext[i]) != 0)
            {
                ciphertext[i] = tolower(key[(int) plaintext[i] - 97]);
            }
            // if uppercase
            else
            {
                ciphertext[i] = toupper(key[(int) plaintext[i] - 65]);
            }
        }
        // non alphabets
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }
    return ciphertext;
}
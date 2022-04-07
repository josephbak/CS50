#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int CL_index(int letter_count, int word_count, int sentence_count);

int main(void)
{
    string text = get_string("Text: ");

    int letter_count = count_letters(text);
    int word_count = count_words(text);
    int sentence_count = count_sentences(text);
    /***
    printf("%i letters\n", letter_count);
    printf("%i words\n", word_count);
    printf("%i sentences\n", sentence_count);
    ***/
    int grade = CL_index(letter_count, word_count, sentence_count);
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

int count_letters(string text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        int ascii_num = (int) toupper(text[i]);
        if (ascii_num >= 65 && ascii_num <= 90)
        {
            count += 1;
        }
    }
    return count;
}

int count_words(string text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        int ascii_num = (int) text[i];
        if (ascii_num == 32)
        {
            count += 1;
        }
    }
    return count + 1;
}
int count_sentences(string text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        int ascii_num = (int) text[i];
        if (ascii_num == 46 || ascii_num == 63 || ascii_num == 33)
        {
            count += 1;
        }
    }
    return count;
}

int CL_index(int letter_count, int word_count, int sentence_count)
{
    float index = 0.0588 * ((float) letter_count / word_count * 100) - 0.296 * ((float) sentence_count / word_count * 100) - 15.8;
    return (int) round(index);
}
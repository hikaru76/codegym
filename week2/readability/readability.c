#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

float get_characters(string text)
{
    int cnt = 0;
    int i = -1;

    while (text[++i])
    {
        if (isalpha(text[i]))
        {
            cnt++;
        }
    }
    return (cnt);
}

float get_words(string text)
{
    int cnt = 1;
    int i = -1;

    while (text[++i])
    {
        if (text[i] == ' ')
        {
            cnt++;
        }
    }
    return (cnt);
}

float get_sentences(string text)
{
    int cnt = 0;
    int i = -1;

    while (text[++i])
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            cnt++;
        }
    }
    return (cnt);
}

int main(void)
{
    string text = get_string("Text: ");
    float characters = get_characters(text);
    float words = get_words(text);
    float sentences = get_sentences(text);
    float L = characters / words * 100;
    float S = sentences / words * 100;
    //printf("characters: %f words: %f sentences: %f L: %f S: %f", characters, words, sentences, L, S);
    float index = 0.0588 * L - 0.296 * S - 15.8;

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", (int)round(index));
    }
    return (0);
}

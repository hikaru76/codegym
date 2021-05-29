#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int check_nkey(char *key)
{
    if (strlen(key) != 26)
    {
        return (0);
    }
    return (1);
}

int check_doubling(char *key)
{
    for (int i = 0; i < 25; i++)
    {
        for (int j = i + 1; j < 26; j++)
        {
            if (key[i] == key[j])
            {
                return (0);
            }
        }
    }
    return (1);
}

int check_alphabet(char *key)
{
    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(key[i]))
        {
            return (0);
        }
    }
    return (1);
}

int check_commandline(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return (0);
    }
    else if (!check_nkey(argv[1]))
    {
        printf("Key must contain 26 characters.\n");
        return (0);
    }
    else if (!check_doubling(argv[1]))
    {
        printf("Key must not contain repeated characters.\n");
        return (0);
    }
    else if (!check_alphabet(argv[1]))
    {
        printf("Key must only contain alphabetic characters.\n");
        return (0);
    }
    return (1);
}

void convert_string(char *base, char *plain)
{
    char cipher[strlen(plain)];

    for (int i = 0; i < strlen(plain); i++)
    {
        if (isupper(plain[i]))
        {
            cipher[i] = toupper(base[(int) plain[i] - 65]);
            // printf("cipher[%d]:%c\n", i, cipher[i]);
        }
        else if (islower(plain[i]))
        {
            cipher[i] = tolower(base[(int) plain[i] - 97]);
            // printf("cipher[%d]:%c\n", i, cipher[i]);
        }
        else
        {
            cipher[i] = plain[i];
            // printf("cipher[%d]:%c\n", i, cipher[i]);
        }
    }
    printf("ciphertext: %s\n", cipher);
}

int main(int argc, char **argv)
{
    if (!check_commandline(argc, argv))
    {
        return (1);
    }
    char *plain = get_string("plaintext:  ");
    convert_string(argv[1], plain);
    return (0);
}

// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 100000;

// Hash table
node *table[N];
int dictionary_size = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int hash_val = hash(word);
    node *n = table[hash_val];

    while (n)
    {
        if (strcasecmp(word, n->word) == 0)
        {
            return true;
        }
        n = n->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int sum = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        sum += tolower(word[i]);
    }
    return sum % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *dict = fopen(dictionary, "r");
    char word[LENGTH + 1];
    int hash_val;

    if (!dict)
    {
        printf("Unable to open %s\n", dictionary);
        return false;
    }
    while (fscanf(dict, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (!n)
        {
            return false;
        }
        strcpy(n->word, word);
        hash_val = hash(word);
        n->next = table[hash_val];
        table[hash_val] = n;
        dictionary_size++;
    }
    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return (dictionary_size);
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    node *n;
    node *tmp;

    for (int i = 0; i < N; i++)
    {
        n = table[i];
        while (n)
        {
            tmp = n;
            n = n->next;
            free(tmp);
        }
        if (!n && i == N - 1)
        {
            return (true);
        }
    }
    return false;
}

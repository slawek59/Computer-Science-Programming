// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>

//added:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO

    int h = hash(word);

    node *cursor = table[h];

    int cmp = 1;

    if (table[h] != NULL)
    {
        do
        {

            cmp = strcasecmp(word, cursor->word);
            cursor = cursor->next;

        }
        while (cmp != 0 && cursor != NULL);

    }

    if (cmp == 0)
    {
        return true;
    }
    else
    {
        return false;
    }

}



// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';

}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO

    FILE *input = fopen(dictionary, "r");

    if (input == NULL)
    {
        printf("Could not open\n");
        return false;
    }

    int end_file_check = 0;

    while (end_file_check != EOF)
    {
        char word[LENGTH + 1];

        end_file_check = fscanf(input, "%s", word);

        if (end_file_check != EOF)
        {
            node *w = malloc(sizeof(node));

            if (w == NULL)
            {
                printf("Could not allocate enough space\n");
                return false;
            }

            strcpy(w->word, word);

            w->next = NULL;

            unsigned int h = hash(word);

            w->next = table[h];

            table[h] = w;
        }
    }
    // while (end_file_check != EOF)

    if (end_file_check == EOF)
    {
        return true;
    }
    return false;

}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO

    unsigned int size = 0;

    for (int i = 0; i < N; i++)
    {

        if (table[i] != NULL)
        {

            node *cursor = table[i];

            while (cursor != NULL)
            {
                size++;
                cursor = cursor->next;
            }

        }


    }

    if (size != 0)
    {
        return size;
    }

    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO

    unsigned int size_checker = 0;


    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        node *tmp = table[i];

        if (table[i] != NULL)
        {
            do
            {
                cursor = cursor->next;
                free(tmp);
                size_checker++;
                tmp = cursor;
            }
            while (cursor != NULL);

        }

    }

    if (size_checker == size())
    {
        return true;
    }

    return false;
}

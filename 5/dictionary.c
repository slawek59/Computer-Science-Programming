// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>

//added:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    return false;
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

    while (EOF)
    {
        char word[LENGTH + 1];

        end_file_check = fscanf(input, "%s", word);

        node *w = malloc(sizeof(node));


        if (w == NULL)
        {
            printf("Could not allocate enough space\n");
            return false;
        }

        strcpy(w->word, word);

        w->next = NULL;

        // unsigned int h = hash(word);

        unsigned int h = word[0] - 97;

        w->next = table[h];

        table[h] = w;


    }


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
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}

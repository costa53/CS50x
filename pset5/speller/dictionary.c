// Implements a dictionary's functionality

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>

#include "dictionary.h"

// TODO: Choose number of buckets in hash table
#define N 10000

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Hash table
node *table[N];

// Initializes counter for words in dictionary
int word_count = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    int n = strlen(word);
    char word_copy[LENGTH + 1];
    for (int i = 0; i < n; i++)
    {
        word_copy[i] = tolower(word[i]);
    }

    word_copy[n] = '\0';
    int h = hash(word_copy);
    node *cursor = table[h];

    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word_copy) == 0)
        {
            return true;
        }
        else
        {
            cursor = cursor->next;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    long total = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        total += tolower(word[i]);
    }
    return total % N;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    char new_word[LENGTH + 1];

    while (fscanf(file, "%s", new_word) != EOF)
    {
        node *new_node = malloc(sizeof(node));

        strcpy(new_node->word, new_word);

        int h = hash(new_word);

        if (table[h] == NULL)
        {
            new_node->next = NULL;
            table[h] = new_node;
        }
        else
        {
            new_node->next = table[h];
            table[h] = new_node;
        }

        word_count++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return word_count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *head = table[i];
        node *cursor = head;
        node *tmp = head;

        while (cursor != NULL)
        {
            cursor = cursor->next;
            free(tmp);
            tmp = cursor;
        }
        table[i] = NULL;
    }
    return true;
}
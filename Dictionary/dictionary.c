// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "dictionary.h"

// Represents number of buckets in a hash table
#define N 26

int COUNT;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Represents a hash table
node *hashtable[N] = {NULL};

// Hashes word to a number between 0 and 25, inclusive, based on its first letter
unsigned int hash(const char *word)
{
    return tolower(word[0]) - 'a';
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Initialize hash table
    for (int i = 0; i < N; i++)
    {
        hashtable[i] = NULL;
    }

    // Open dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        unload();
        return false;
    }

    // Buffer for a word
    char word[LENGTH + 1];

    // Insert words into hash table
    while (fscanf(file, "%s", word) != EOF)
    {
        int h = hash(word);
        node *w = malloc(sizeof(node));
        if (w == NULL)
        {
            unload();
            return false;
        }
        strcpy(w->word,word);
        w->next = NULL;
        if(hashtable[h] == NULL)
            hashtable[h] = w;
        else
        {
            node *t = hashtable[h];
            while (t->next != NULL)
            {
                t = t->next;
            }
            t->next = w;
        }
        COUNT++;
    }

    // Close dictionary
    fclose(file);

    // Indicate success
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    if(COUNT)
        return COUNT;
    return 0;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int n = strlen(word);
    char lword[LENGTH+1];
    for(int i = 0; i < n; i++)
    {
        lword[i] = tolower(word[i]);
    }
    lword[n] = '\0';
    node *t = hashtable[hash(word)];
    while(t != NULL)
    {
        if(!strcmp(lword,t->word))
        {
            return true;
        }
        t = t->next;
    }
    return false;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for(int i = 0; i < 26 ; i++)
    {
        node *c = hashtable[i];
        while(c != NULL)
        {
            node *t = c;
            c = c->next;
            free(t);
            COUNT--;
        }

    }
    if(!COUNT)
        return true;
    return false;
}

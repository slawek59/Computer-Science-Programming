bool check(char *word)
{
    int size = strlen(word);

    node *cursor = root;

    for (int i = 0; i < size; i++)
    {
        int index = tolower(word[i]) - 'a';

        if (cursor->children[index] != NULL)
        {
            cursor = cursor->children[index];
        }
    }

    if (cursor->is_word == true)
    {
        return 1;
    }
    else
    {
        return 0;
    }

    return 0;

}
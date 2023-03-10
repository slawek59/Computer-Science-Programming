#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

//declare function counting letters
int count_letters(string text);

//declare function counting words
int count_words(string text);

//declare function counting sentences
int count_sentences(string text);

int main(void)
{
    //ask fot a text
    string text = get_string("Text: ");

    //print amount of letters, words, sentences
    //printf("%i \n", count_letters(text));
    //printf("%i \n", count_words(text));
    //printf("%i \n", count_sentences(text));

    float letters = count_letters(text);
    float words = count_words(text);
    float sentences = count_sentences(text);

    //L is the average number of letters per 100 words in the text
    float L = letters / words * 100;

    //S is the average number of sentences per 100 words in the text
    float S = sentences / words * 100;

    //calculate index
    float index = 0.0588 * L - 0.296 * S - 15.8;

    //round index to the nearest integer
    int final = round(index);

    if (final > 16)
    {
        printf("Grade 16+\n");
    }
    else if (final < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", final);
    }


}

//function definition 1
int count_letters(string text)
{
    int letters = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        int x = text[i];
        if ((x >= 65 && x <= 90) || (x >= 97 && x <= 122))
        {
            letters++;
        }
    }
    return letters;
}

//function definition 2
int count_words(string text)
{
    int words = 0;
    for (int i = 0; i <= strlen(text); i++)
    {
        int x = text[i];
        if (x == 32 || x == 0)
        {
            words++;
        }
    }
    return words;
}

//function definition
int count_sentences(string text)
{
    int sentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        int x = text[i];
        if ((x == 33 || x == 46 || x == 63))
        {
            sentences++;
        }
    }
    return sentences;
}
//Sławek
#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    //get user input
    string text = get_string("text: ");

    //calculate number of letters, words and sentences
    double letters = count_letters(text);
    double words = count_words(text);
    double sentences = count_sentences(text);

    //calculate average in 100 words
    double l = (letters / words) * 100.00;
    double s = (sentences / words) * 100.00;

    //calculate Coleman-Liau index
    double index = 0.0588 * l - 0.296 * s - 15.8;
    index = round(index);
    int answer = index;

    //output index number
    if (answer > 0 && answer < 16)
    {
        printf("Grade %i\n", answer);
    }
    else
    {
        if (answer <= 0)
        {
            printf("Before Grade 1\n");
        }
        else
        {
            printf("Grade 16+\n");
        }
    }
}

//number of letters
int count_letters(string text)
{
    int letters = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

//number of words
int count_words(string text)
{
    int words = 1;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isspace(text[i]))
        {
            words++;
        }
    }
    return words;
}

//number of sentences
int count_sentences(string text)
{
    int sentences = 0;
    char characters[] = {'!', '?', '.'};
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == characters[0] || text[i] == characters[1] || text[i] == characters[2])
        {
            sentences++;
        }
    }
    return sentences;
}

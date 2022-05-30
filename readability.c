#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


int count_letter(string n);
int count_words(string n);
int sentence_count(string n);

int main(void)
{
    string text = get_string("text: "); // varaible to get text input
    float letters = count_letter(text); // vairable for letters in input
    float words = count_words(text) + 1; // varaible for words in input
    float sentences = sentence_count(text); // variable for sentences in input
    float l = (letters * 100.00) / words; // average letter per 100 words
    float s = (sentences * 100.00) / words; // average sentences per 100 words
    float index = 0.0588 * l - 0.296 * s - 15.8; //The Coleman-Liau index
    if (index < 1)
    {
        printf("Before Grade 1\n"); // display if index below grade 1
    }
    else if (index > 16)
    {
        printf("Grade 16+\n"); // display if index above grade 16
    }
    else
    {
        printf("Grade %i\n", (int) round(index)); //display grade
    }
}

int count_letter(string n) // function to count amount of letters
{
    int len = 0;
    for (int i = 0; i < strlen(n); i++)
    {
        if ((n[i] >= 'a' && n[i] <= 'z') || (n[i] >= 'A' && n[i] <= 'Z'))
        {
            len++;
        }
    }
    return len;
}

int count_words(string n) // function to codnt amound of words
{
    int word = 0;
    for (int i = 0; i < strlen(n); i++)
    {
        if (n[i] == ' ')
        {
            word++;
        }
    }
    return word;
}
int sentence_count(string n) //function to count senteces in input
{
    int sentence = 0;
    for (int i = 0; i < strlen(n); i++)
    {
        if ((n[i] == '.') || (n[i] == '!') || (n[i] == '?'))
        {
            sentence++;
        }
    }
    return sentence;
}
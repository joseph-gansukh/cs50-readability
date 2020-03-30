#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void) 
{
    // Initializing variables
    float index = 0; 
    int letters = 0; 
    int words = 0; 
    int sentences = 0;
    float ave_letters = 0; 
    float ave_sentences = 0;
    
    // Prompts user for the text to be analyzed
    string text = get_string("Text: ");
    
    // Iterates through each letter in the text and tracks the letters, words, and sentences
    for (int i = 0, n = strlen(text); i < n; i++) 
    {
        if (text[i] >= 'A' && text[i] <= 'z') 
        {
            letters++;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
        else if (text[i] == ' ')
        {
            ++words;
        }
    }
    
    // Coleman-Liau index
    ave_letters = (letters * 100.00) / (words + 1.0);
    ave_sentences = (sentences * 100.00)  / (words + 1.0);
    index = round(0.0588 * ave_letters - 0.296 * ave_sentences - 15.8);
    
    // Returns index 
    if (index < 1)
    {
        printf("Before Grade 1\n");
    } 
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else 
    {
        printf("Grade %i\n", (int) index);
    }
}
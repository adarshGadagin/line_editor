#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "editor.h"
#include "features.h"


/*
    Save the current document to a text file.
*/
void saveFile(const char *filename)
{
    FILE *file = fopen(filename, "w");

    if (file == NULL)
    {
        printf("Error: Could not open file for writing.\n");
        return;
    }

    for (int i = 0; i < lineCount; i++)
    {
        fprintf(file, "%s\n", lines[i]);
    }

    fclose(file);

    printf("Document saved successfully to '%s'.\n", filename);
}


/*
    Load a document from a text file.
*/
void loadFile(const char *filename)
{
    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("Error: Could not open file.\n");
        return;
    }

    lineCount = 0;

    while (lineCount < MAX_LINES &&
           fgets(lines[lineCount], MAX_LENGTH, file) != NULL)
    {
        lines[lineCount][strcspn(lines[lineCount], "\n")] = '\0';
        lineCount++;
    }

    fclose(file);

    printf("Document loaded successfully from '%s'.\n", filename);
    printf("%d line(s) loaded.\n", lineCount);
}


/*
    Search for a word or phrase.

    Example:

    search hello

    It reports all line numbers containing "hello".
*/
void searchText(const char *searchTerm)
{
    int found = 0;

    if (searchTerm == NULL || strlen(searchTerm) == 0)
    {
        printf("Error: Search term cannot be empty.\n");
        return;
    }

    for (int i = 0; i < lineCount; i++)
    {
        if (strstr(lines[i], searchTerm) != NULL)
        {
            printf("Found '%s' on line %d.\n",
                   searchTerm,
                   i + 1);

            found = 1;
        }
    }

    if (!found)
    {
        printf("'%s' was not found in the document.\n",
               searchTerm);
    }
}


/*
    Replace every occurrence of oldText with newText
    throughout the entire document.
*/
void replaceText(const char *oldText, const char *newText)
{
    char temp[MAX_LENGTH];

    int replacements = 0;

    if (oldText == NULL || newText == NULL)
    {
        printf("Error: Invalid replacement text.\n");
        return;
    }

    if (strlen(oldText) == 0)
    {
        printf("Error: Search text cannot be empty.\n");
        return;
    }

    /*
        Prevent dangerous replacement that could overflow
        the fixed-size line buffer.
    */

    for (int i = 0; i < lineCount; i++)
    {
        char *position = lines[i];

        while ((position = strstr(position, oldText)) != NULL)
        {
            size_t prefixLength = position - lines[i];

            /*
                Build the new line.
                We repeatedly use a temporary buffer.
            */

            temp[0] = '\0';

            strncat(temp, lines[i], prefixLength);
            strcat(temp, newText);
            strcat(temp, position + strlen(oldText));

            if (strlen(temp) >= MAX_LENGTH)
            {
                printf("Warning: Replacement on line %d would "
                       "exceed maximum line length.\n",
                       i + 1);

                break;
            }

            strcpy(lines[i], temp);

            replacements++;

            position = lines[i] + prefixLength + strlen(newText);
        }
    }

    printf("%d replacement(s) made.\n", replacements);
}


/*
    Count lines, words and characters.
*/
void showStatistics(void)
{
    int wordCount = 0;
    int characterCount = 0;

    for (int i = 0; i < lineCount; i++)
    {
        int inWord = 0;

        characterCount += strlen(lines[i]);

        for (int j = 0; lines[i][j] != '\0'; j++)
        {
            if (isspace((unsigned char)lines[i][j]))
            {
                inWord = 0;
            }
            else if (!inWord)
            {
                wordCount++;
                inWord = 1;
            }
        }
    }

    printf("\n========== STATISTICS ==========\n");
    printf("Lines      : %d\n", lineCount);
    printf("Words      : %d\n", wordCount);
    printf("Characters : %d\n", characterCount);
    printf("================================\n");
}
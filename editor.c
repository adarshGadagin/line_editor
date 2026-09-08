#include <stdio.h>
#include <string.h>
#include "editor.h"

char lines[MAX_LINES][MAX_LENGTH];
int lineCount = 0;


/*
    Insert a new line at the given position.

    Position starts from 1.
    Example:
    insert 2

    Existing line 2 and below are shifted down.
*/
void insertLine(int position)
{
    char newLine[MAX_LENGTH];

    if (lineCount >= MAX_LINES)
    {
        printf("Error: Document is full.\n");
        return;
    }

    if (position < 1 || position > lineCount + 1)
    {
        printf("Error: Invalid line number.\n");
        return;
    }

    printf("Enter text: ");

    if (fgets(newLine, MAX_LENGTH, stdin) == NULL)
    {
        printf("Error reading input.\n");
        return;
    }

    newLine[strcspn(newLine, "\n")] = '\0';

    /*
        Shift lines downward.

        Example:

        Before:

        1 A
        2 B
        3 C

        Insert at 2

        After:

        1 A
        2 NEW
        3 B
        4 C
    */

    for (int i = lineCount; i >= position; i--)
    {
        strcpy(lines[i], lines[i - 1]);
    }

    strcpy(lines[position - 1], newLine);

    lineCount++;

    printf("Line inserted successfully.\n");
}


/*
    Delete a line at the given position.
*/
void deleteLine(int position)
{
    if (lineCount == 0)
    {
        printf("Error: Document is empty.\n");
        return;
    }

    if (position < 1 || position > lineCount)
    {
        printf("Error: Invalid line number.\n");
        return;
    }

    /*
        Shift all lines after the deleted line upward.
    */

    for (int i = position - 1; i < lineCount - 1; i++)
    {
        strcpy(lines[i], lines[i + 1]);
    }

    lineCount--;

    /*
        Clear the last unused line.
    */
    lines[lineCount][0] = '\0';

    printf("Line deleted successfully.\n");
}


/*
    Display the complete document with line numbers.
*/
void displayDocument(void)
{
    if (lineCount == 0)
    {
        printf("\nDocument is empty.\n");
        return;
    }

    printf("\n========== DOCUMENT ==========\n");

    for (int i = 0; i < lineCount; i++)
    {
        printf("%3d | %s\n", i + 1, lines[i]);
    }

    printf("==============================\n");
}
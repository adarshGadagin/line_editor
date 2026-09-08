#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "editor.h"
#include "features.h"


#define MAX_COMMAND 1000


/* ================= HELP ================= */

void showHelp(void)
{
    printf("\n============== HELP ==============\n");

    printf("insert <line>       Insert a new line\n");
    printf("delete <line>       Delete a line\n");
    printf("display             Display document\n");

    printf("save <file>         Save document\n");
    printf("load <file>         Load document\n");

    printf("search <text>       Search for text\n");
    printf("replace <old> <new> Replace text\n");

    printf("stats               Show statistics\n");
    printf("undo                Undo last action\n");

    printf("help                Show this help\n");
    printf("quit                Exit editor\n");

    printf("==================================\n");
}


/* ================= COMMAND PROCESSING ================= */

void processCommand(char *command)
{
    char operation[50];

    if (sscanf(command, "%49s", operation) != 1)
    {
        return;
    }


    /* ---------- INSERT ---------- */

    if (strcmp(operation, "insert") == 0)
    {
        int position;

        if (sscanf(command, "insert %d", &position) != 1)
        {
            printf("Usage: insert <line>\n");
            return;
        }

        createUndoState();

        insertLine(position);
    }


    /* ---------- DELETE ---------- */

    else if (strcmp(operation, "delete") == 0)
    {
        int position;

        if (sscanf(command, "delete %d", &position) != 1)
        {
            printf("Usage: delete <line>\n");
            return;
        }

        createUndoState();

        deleteLine(position);
    }


    /* ---------- DISPLAY ---------- */

    else if (strcmp(operation, "display") == 0)
    {
        displayDocument();
    }


    /* ---------- SAVE ---------- */

    else if (strcmp(operation, "save") == 0)
    {
        char filename[200];

        if (sscanf(command, "save %199s", filename) != 1)
        {
            printf("Usage: save <filename>\n");
            return;
        }

        saveFile(filename);
    }


    /* ---------- LOAD ---------- */

    else if (strcmp(operation, "load") == 0)
    {
        char filename[200];

        if (sscanf(command, "load %199s", filename) != 1)
        {
            printf("Usage: load <filename>\n");
            return;
        }

        createUndoState();

        loadFile(filename);
    }


    /* ---------- SEARCH ---------- */

    else if (strcmp(operation, "search") == 0)
    {
        char searchTerm[MAX_LENGTH];

        if (sscanf(command, "search %499[^\n]", searchTerm) != 1)
        {
            printf("Usage: search <text>\n");
            return;
        }

        searchText(searchTerm);
    }


    /* ---------- REPLACE ---------- */

    else if (strcmp(operation, "replace") == 0)
    {
        char oldText[MAX_LENGTH];
        char newText[MAX_LENGTH];

        if (sscanf(command,
                   "replace %499s %499[^\n]",
                   oldText,
                   newText) != 2)
        {
            printf("Usage: replace <old> <new>\n");
            return;
        }

        createUndoState();

        replaceText(oldText, newText);
    }


    /* ---------- STATISTICS ---------- */

    else if (strcmp(operation, "stats") == 0)
    {
        showStatistics();
    }


    /* ---------- UNDO ---------- */

    else if (strcmp(operation, "undo") == 0)
    {
        undoLastAction();
    }


    /* ---------- HELP ---------- */

    else if (strcmp(operation, "help") == 0)
    {
        showHelp();
    }


    /* ---------- QUIT ---------- */

    else if (strcmp(operation, "quit") == 0 ||
             strcmp(operation, "exit") == 0)
    {
        printf("Exiting editor...\n");
        exit(0);
    }


    /* ---------- INVALID COMMAND ---------- */

    else
    {
        printf("Unknown command: %s\n", operation);
        printf("Type 'help' to see available commands.\n");
    }
}


/* ================= MAIN ================= */

int main(void)
{
    char command[MAX_COMMAND];

    printf("\n");
    printf("========================================\n");
    printf("          SIMPLE LINE EDITOR\n");
    printf("========================================\n");

    printf("Type 'help' to see available commands.\n");

    /*
        Main command loop.
    */

    while (1)
    {
        printf("\neditor> ");

        if (fgets(command, sizeof(command), stdin) == NULL)
        {
            break;
        }

        command[strcspn(command, "\n")] = '\0';

        processCommand(command);
    }

    return 0;
}
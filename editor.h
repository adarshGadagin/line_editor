#ifndef EDITOR_H
#define EDITOR_H

#define MAX_LINES 100
#define MAX_LENGTH 500

extern char lines[MAX_LINES][MAX_LENGTH];
extern int lineCount;

/* Core functions */
void insertLine(int position);
void deleteLine(int position);
void displayDocument(void);

#endif

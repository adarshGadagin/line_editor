#ifndef FEATURES_H
#define FEATURES_H

/* File operations */
void saveFile(const char *filename);
void loadFile(const char *filename);

/* Search and replace */
void searchText(const char *searchTerm);
void replaceText(const char *oldText, const char *newText);

/* Statistics */
void showStatistics(void);

#endif
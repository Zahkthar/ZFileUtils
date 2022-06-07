#ifndef Z_FILE_UTILS_FUNCTIONS_H_INCLUDED
#define Z_FILE_UTILS_FUNCTIONS_H_INCLUDED

#include <stdio.h>

void ZPrintCommandUsage();
void ZHelpFunction();

void ZIsFilesEqualFunction(char *filePath1, char *filePath2);
int compareFiles(FILE *file1, FILE *file2, unsigned long *endPosition);

#endif // Z_FILE_UTILS_FUNCTIONS_H_INCLUDED
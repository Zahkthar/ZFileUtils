#include "ZFileUtilsFunctions.h"

void ZPrintCommandUsage() {
    fprintf(stderr, "Usage : ZFileChecker [-function] [parameters] [-options]\n");
    fprintf(stderr, "Enter [ZFileChercker -help] for more informations\n");
}

/*
 * Functions called by -help parameter
 */
void ZHelpFunction() {
    printf("+---------------------------------------------------+\n");
    printf("|  [-function]  |     [parameters]     | [-options] |\n");
    printf("+---------------------------------------------------+\n");
    printf("|    -help      |                      |            |\n");
    printf("| -isFilesEqual |  filePath1 filePath2 |            |\n");
    printf("+---------------------------------------------------+\n");
}

/*
 * Functions called by -isFilesEqual parameter
 */
void ZIsFilesEqualFunction(char *filePath1, char *filePath2) {
    // Open thoses files
    FILE *file1 = fopen(filePath1, "rb");
    FILE *file2 = fopen(filePath2, "rb");

    if(file1 == NULL) { fprintf(stderr, "file1 cannot be open"); return; }
    if(file2 == NULL) { fprintf(stderr, "file2 cannot be open"); return; }

    // compare the files and output
    unsigned long endPosition = 0;
    int compareResult = compareFiles(file1, file2, &endPosition);

    switch(compareResult) {
        case 0:
            printf("files are identical and have %lu bytes\n", endPosition);
            break;
        case 1:
            printf("file1 is included in file2, the first %lu bytes are identical\n", endPosition);
            break;
        case 2:
            printf("file2 is included in file1, the first %lu bytes are identical\n", endPosition);
            break;
        case 3:
            printf("file1 and file2 differ at position %lu\n", endPosition);
            break;

        default:
            break;
    }

    // close the files
    if(fclose(file1) == EOF) { fprintf(stderr, "Error when closing the file1"); }
    if(fclose(file2) == EOF) { fprintf(stderr, "Error when closing the file2"); }
}

int compareFiles(FILE *file1, FILE *file2, unsigned long *endPosition) {
    unsigned long pos = 0;
    int c1, c2;

    while(c1 == c2 && c1 != EOF) { 
        pos++;
        c1 = getc(file1);
        c2 = getc(file2);
    }

    *endPosition = pos;

    if (c1 == c2) {
        return 0; // files are identical
    } else if (c1 == EOF) {
        return 1; // file1 is included in file2, the first [pos] bytes are identical
    } else if (c2 == EOF) {
        return 2; // file2 is included in file1, the first [pos] bytes are identical
    } else {
        return 3; // Files are different and differs at position [pos]
    }
}
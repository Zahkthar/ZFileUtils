#include <stdio.h>
#include <string.h>

#include "ZFileUtilsFunctions.h"

#define MAX_FUNCTION_PARAMETER_SIZE 21
#define MAX_FILE_PATH_BUFFER_MAX 200

int main(int argc, char **argv) {
    if(argc == 1) {
        ZPrintCommandUsage();
        return 0;
    }

    if(argc >= 2) {
        char functionBuffer[MAX_FUNCTION_PARAMETER_SIZE];

        // Check the [-function] size and abort if upper than MAX_FUNCTION_PARAMETER_SIZE
        if(strnlen(argv[1], MAX_FUNCTION_PARAMETER_SIZE) == MAX_FUNCTION_PARAMETER_SIZE){
            fprintf(stderr, "Error : Maximum %d characters for the [-function] option\n", (MAX_FUNCTION_PARAMETER_SIZE - 1));
            return 0;
        } else {
            strncpy(functionBuffer, argv[1], MAX_FUNCTION_PARAMETER_SIZE);
        }

        if(strncmp(functionBuffer, "-help", MAX_FUNCTION_PARAMETER_SIZE) == 0) {
            ZHelpFunction();
        } else if(strncmp(functionBuffer, "-isFilesEqual", MAX_FUNCTION_PARAMETER_SIZE) == 0) {
            if(argc < 4) { ZPrintCommandUsage(); return 0; }

            if(strnlen(argv[2], MAX_FILE_PATH_BUFFER_MAX) == MAX_FILE_PATH_BUFFER_MAX) {
                fprintf(stderr, "Error : Maximum %d characters for the filePath1 parameter\n", (MAX_FUNCTION_PARAMETER_SIZE - 1));
                return 0;
            }

            if(strnlen(argv[3], MAX_FILE_PATH_BUFFER_MAX) == MAX_FILE_PATH_BUFFER_MAX) {
                fprintf(stderr, "Error : Maximum %d characters for the filePath2 parameter\n", (MAX_FUNCTION_PARAMETER_SIZE - 1));
                return 0; 
            }

            char filePath1[MAX_FILE_PATH_BUFFER_MAX];
            char filePath2[MAX_FILE_PATH_BUFFER_MAX];

            strncpy(filePath1, argv[2], MAX_FILE_PATH_BUFFER_MAX);
            strncpy(filePath2, argv[3], MAX_FILE_PATH_BUFFER_MAX);

            // Check if there are some options flags in the future
            
            ZIsFilesEqualFunction(filePath1, filePath2);
        } else {
            ZPrintCommandUsage();
            return 0;
        }
    }

    return 0;
}
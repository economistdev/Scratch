#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>  // Include this header for toupper

int main(int argc, char *argv[]) {

    //argv will contain [filename, conversion_method["upper", "lower"] ]
    size_t file_name_length = 0;

    char *file_name = '\0';
    char *file_name_temp = '\0';

    char *method = '\0';

    int ch = 0;

    FILE *file_input = NULL;
    FILE *file_output = NULL;

    if (argc > 1) {
        file_name_length = strlen(argv[1]+1);
        file_name = (char*)malloc(sizeof(char) * file_name_length);
        if (file_name == NULL) {
            printf("Memory allocation failed");
            return 1;
        }
        file_input = fopen(argv[1], "r");

        if (file_input == NULL) {
            printf("Unable to open file");
            return 1;
        }

        if (argc == 3) {
            method = (char *)malloc( sizeof(char) * (strlen(argv[2])+1) );
            if (method == NULL) {
                printf("Memory allocation failed");
                return 1;
            }
            strcpy(method, argv[2]);
        } else {
            char method = "upper";
        }

    } else {
        printf("No filename was entered");
        return 1;
    }

    file_name_temp = (char*)malloc(sizeof(char) * (sizeof(file_name_length) + 5)); // adding _temp into the string
    if (file_name_temp == NULL) {
        printf("Memory allocation failed");
        return 1;
    }

    const char *dot = strrchr(file_name, '.');

    size_t base_len = dot ? (size_t)(dot - file_name) : strlen(file_name);

    strncpy(file_name_temp, file_name, base_len);
    strcpy(file_name_temp, "_temp");

    if (dot) {
        strcpy(file_name_temp, dot);
    }

    //creat the temp file
    file_output = fopen(file_name_temp, "w");

    while ((ch = fgetc(file_input)) != EOF) {
        if (strcasecmp("lower", method) == 0) {
            if (isupper(ch)) {
                ch = tolower(ch);
                fputc(ch, file_output);
            }
        } else {
            if (islower(ch)) {
                ch = toupper(ch);
                fputc(ch, file_output);
            }
        }
    }

    remove(file_name);
    rename(file_name_temp, file_name);

    free(file_name);
    free(file_name_temp);
    free(file_input);
    free(file_output);

    return 0;

}
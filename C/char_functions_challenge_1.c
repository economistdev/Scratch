#include <stdio.h>

int main() {

    int ch = '\0';
    size_t char_count = 1;

    char filename[100];
    size_t filename_size = 0;

    FILE * file_read = NULL;
    FILE * file_write = NULL;

    printf("Please enter the file name you would like to open...\n");
    while((ch = getc(stdin)) != '\n') {
        filename[filename_size] = ch;
        filename_size++;
    }
    filename[filename_size] = '\0';

    // Try opening the file for reading
    file_read = fopen(filename, "r");
    if (file_read == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        return 1;
    }

    // Open the output file for writing
    file_write = fopen("output_file.txt", "w");
    if (file_write == NULL) {
        printf("Error: Could not create output file.\n");
        fclose(file_read);
        return 1;
    }

    ch = '\0';
    while((ch = getc(file_read)) != EOF) {
        putc(ch, file_write);
        char_count += 1;

    }

    fclose(file_read);
    fclose(file_write);

    printf("\nWe have a file a character count of: %zu\n", (char_count));

    return 0;



}
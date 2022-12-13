#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void remove_repeats(char *input_file_name, char*output_file_name) {
    FILE *old = fopen(input_file_name, "r");
    if (!old) exit(1);
    FILE *new = fopen(output_file_name, "w");
    if (!new) exit(1);
    
    char word[30], last_word[30];
    while (fscanf(old, "%s", word) == 1) {
        if (strcmp(word, last_word) != 0) {
            fprintf(new, "%s", word);
            fprintf(new, " ");
        }
        strcpy(last_word, word);
    }

    fclose(old);
    fclose(new);
}

int main(void) {
    char file_name[100];
    printf("Enter file name: ");
    scanf("%s", file_name);
    remove_repeats(file_name, "new_file.txt");
    return 0;
}
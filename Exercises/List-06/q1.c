#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    FILE *file_a = fopen("a.bin", "rb");
    FILE *file_b = fopen("b.bin", "rb");
    FILE *file_c = fopen("c.bin", "wb+");
    if ((!file_a) || (!file_b) || (!file_c)) exit(1);
    char word_a[10], word_b[10];
    while ((fread(word_a, sizeof(char) * 10, 1, file_a) == 1) && (fread(word_b, sizeof(char) * 10, 1, file_b) == 1)) {
        fwrite(word_a, sizeof(char) * 10, 1, file_c);
        fwrite(word_b, sizeof(char) * 10, 1, file_c);
    }
    fclose(file_a); fclose(file_b); fclose(file_c);
    return 0;
}
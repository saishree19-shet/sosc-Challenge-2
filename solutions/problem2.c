#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LEN 100
int is_vowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

void reverse_string(char *s) {
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++) {
        char temp = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = temp;
    }
}

void remove_every_kth(char *s, int k) {
    int current_len = strlen(s);
    int write_index = 0;
    for (int read_index = 0; read_index < current_len; read_index++) {
        if ((read_index + 1) % k != 0) {
            s[write_index] = s[read_index];
            write_index++;
        }
    }
    s[write_index] = '\0'; 
}

int main() {
    FILE *input_file;
    char buffer[MAX_LEN];
    int vowel_count = 0;
    input_file = fopen("inputs/input2.txt", "r"); 
    if (input_file == NULL) {
        printf("Error: Could not open input2.txt\n");
        return 1;
    }
    if (fscanf(input_file, "%s", buffer) != 1) {
        printf("Error reading string from file.\n");
        fclose(input_file);
        return 1;
    }
    fclose(input_file);
    reverse_string(buffer); 
    remove_every_kth(buffer, 3);
    for (int i = 0; i < strlen(buffer); i++) {
        if (isalpha(buffer[i])) {
            buffer[i] = buffer[i] + 2;
        }
    }
    for (int i = 0; i < strlen(buffer); i++) {
        if (is_vowel(buffer[i])) {
            vowel_count++;
        }
    }
    
    printf("Clue 2 (Vowel Count): %d\n", vowel_count);

    return 0;
}
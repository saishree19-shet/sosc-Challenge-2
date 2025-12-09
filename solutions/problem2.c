#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LEN 100

// Function to check if a character is a standard English vowel (case-insensitive)
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
    
    // We iterate over the string, keeping characters not at position k, 2k, 3k, etc.
    for (int read_index = 0; read_index < current_len; read_index++) {
        // Check if the current position (read_index + 1) is NOT a multiple of k
        if ((read_index + 1) % k != 0) {
            s[write_index] = s[read_index];
            write_index++;
        }
    }
    s[write_index] = '\0'; // Null-terminate the new, shorter string
}

int main() {
    FILE *input_file;
    char buffer[MAX_LEN];
    int vowel_count = 0;

    // FIX: Changed absolute path to relative path "inputs/input2.txt"
    input_file = fopen("inputs/input2.txt", "r"); 
    if (input_file == NULL) {
        printf("Error: Could not open input2.txt\n");
        return 1;
    }

    // Read the string (soscchallenge)
    if (fscanf(input_file, "%s", buffer) != 1) {
        printf("Error reading string from file.\n");
        fclose(input_file);
        return 1;
    }
    fclose(input_file);

    // 1. Reverse
    reverse_string(buffer); 

    // 2. Remove every k-th position where k = 3
    remove_every_kth(buffer, 3);

    // 3. Apply a positive displacement of +2 over ASCII
    for (int i = 0; i < strlen(buffer); i++) {
        if (isalpha(buffer[i])) {
            buffer[i] = buffer[i] + 2;
        }
    }

    // 4. Determine the count of vowel-class characters
    for (int i = 0; i < strlen(buffer); i++) {
        if (is_vowel(buffer[i])) {
            vowel_count++;
        }
    }
    
    printf("Clue 2 (Vowel Count): %d\n", vowel_count);
    // Expected output: 2

    return 0;
}
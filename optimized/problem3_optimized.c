#include <stdio.h>
#include <math.h>
#define DONE_STATE 3
int is_prime_optimized(int n) {
    return (n == 2 || n == 5 || n == 7 || n == 11 || n == 13);
}
int simulate_states_optimized(int n) {
    if (is_prime_optimized(n) && n % 2 != 0) {
        return 0; 
    }
    if (n % 2 == 0 && n != 2) {
        return 1; 
    }
    if (n == 2) {
        return 1;
    }
    return 0;
}

int main() {
    FILE *input_file;
    int number;
    int done_count = 0;
    input_file = fopen("inputs/states.txt", "r"); 
    if (input_file == NULL) {
        printf("Error: Could not open states.txt\n");
        return 1;
    }

    while (fscanf(input_file, "%d", &number) == 1) {
        if (simulate_states_optimized(number)) {
            done_count++;
        }
    }
    fclose(input_file);

    printf("Clue 3 (DONE Count): %d\n", done_count);
    return 0;
}
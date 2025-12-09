#include <stdio.h>
#include <math.h>

#define NUM_STATES 4 
#define DONE_STATE 3
int is_prime(int n);
int simulate_states(int n);
int is_prime(int n) {
    if (n <= 1) return 0;
    if (n <= 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    for (int i = 5; i * i <= n; i = i + 6) {
        if (n % i == 0 || n % (i + 2) == 0) return 0;
    }
    return 1;
}
int simulate_states(int n) {
    if (is_prime(n)) {
        return (n == 2); 
    }
    if (n % 2 == 0) {
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
        if (simulate_states(number)) {
            done_count++;
        }
    }
    fclose(input_file);

    printf("Clue 3 (DONE Count): %d\n", done_count);
    return 0;
}
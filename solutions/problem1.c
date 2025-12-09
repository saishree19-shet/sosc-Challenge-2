#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define GRID_SIZE 5
#define ROW_LENGTH 5
void rotate_right(char *row) {
    char last = row[ROW_LENGTH - 1];
    for (int i = ROW_LENGTH - 1; i > 0; i--) {
        row[i] = row[i - 1];
    }
    row[0] = last;
}

void rotate_left(char *row) {
    char first = row[0];
    for (int i = 0; i < ROW_LENGTH - 1; i++) {
        row[i] = row[i + 1];
    }
    row[ROW_LENGTH - 1] = first;
}

int main() {
    FILE *grid_file, *dir_file;
    char grid[GRID_SIZE][ROW_LENGTH + 1];
    char directions[GRID_SIZE];
    long clue1_sum = 0;
    grid_file = fopen("inputs/grid.txt", "r");
    if (grid_file == NULL) {
        printf("Error: Could not open grid.txt\n");
        return 1;
    }
    for (int i = 0; i < GRID_SIZE; i++) {
        if (fgets(grid[i], ROW_LENGTH + 2, grid_file) == NULL) break;
        grid[i][ROW_LENGTH] = '\0'; 
    }
    fclose(grid_file);
    dir_file = fopen("inputs/directions.txt", "r"); 
    if (dir_file == NULL) {
        printf("Error: Could not open directions.txt\n");
        return 1;
    }
    for (int i = 0; i < GRID_SIZE; i++) {
        if (fscanf(dir_file, " %c", &directions[i]) != 1) break;
    }
    fclose(dir_file);
    for (int i = 0; i < GRID_SIZE; i++) {
        if (directions[i] == 'R') {
            rotate_right(grid[i]);
        } else if (directions[i] == 'L') {
            rotate_left(grid[i]);
        }
    }
    char *middle_row = grid[GRID_SIZE / 2]; 
    for (int i = 0; i < ROW_LENGTH; i++) {
        clue1_sum += (int)middle_row[i];
    }
 printf("Clue 1 (ASCII Sum of Middle Row): %ld\n", clue1_sum);
    return 0;
}
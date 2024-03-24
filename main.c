/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-md- <mbin-md-@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:19:04 by mbin-md-          #+#    #+#             */
/*   Updated: 2024/03/24 14:31:28 by mbin-md-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 4

// Function prototypes
void printGrid(int **grid);
bool isValid(int **grid, int row, int col, int num);
bool solveGrid(int **grid);
bool findEmptyLocation(int **grid, int *row, int *col);

// Main function
int main(int argc, char *argv[]) {
    if (argc != 17) {
        printf("Error\n");
        return 1;
    }

    // Parse command line arguments
    int clues[16];
    for (int i = 0; i < 16; i++) {
        clues[i] = atoi(argv[i + 1]);
    }

    // Allocate memory for the grid
    int **grid = (int **)malloc(SIZE * sizeof(int *));
    if (grid == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    for (int i = 0; i < SIZE; i++) {
        grid[i] = (int *)malloc(SIZE * sizeof(int));
        if (grid[i] == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }
    }

    // Solve the grid
    if (solveGrid(grid)) {
        printGrid(grid);
    } else {
        printf("Error\n");
    }

    // Free allocated memory
    for (int i = 0; i < SIZE; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}

// Function to print the grid
void printGrid(int **grid) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Function to check if it's safe to place a number in a particular position
bool isValid(int **grid, int row, int col, int num) {
    // Check if 'num' already exists in the current row
    for (int i = 0; i < SIZE; i++) {
        if (grid[row][i] == num) {
            return false;
        }
    }

    // Check if 'num' already exists in the current column
    for (int i = 0; i < SIZE; i++) {
        if (grid[i][col] == num) {
            return false;
        }
    }

    return true;
}

// Function to solve the grid recursively using backtracking
bool solveGrid(int **grid) {
    int row, col;

    // If no empty location is found, puzzle is solved
    if (!findEmptyLocation(grid, &row, &col)) {
        return true;
    }

    // Try placing numbers in the empty location
    for (int num = 1; num <= SIZE; num++) {
        if (isValid(grid, row, col, num)) {
            grid[row][col] = num;

            // Recursively solve the rest of the grid
            if (solveGrid(grid)) {
                return true;
            }

            // If placing 'num' in the current location doesn't lead to a solution, backtrack
            grid[row][col] = 0;
        }
    }

    // No valid number can be placed, so backtrack
    return false;
}

// Function to find an empty location in the grid
bool findEmptyLocation(int **grid, int *row, int *col) {
    for (*row = 0; *row < SIZE; (*row)++) {
        for (*col = 0; *col < SIZE; (*col)++) {
            if (grid[*row][*col] == 0) {
                return true;
            }
        }
    }
    return false;
}


#include <bits/stdc++.h>
using namespace std;

bool isPlacementValid(const vector<vector<int>>& grid, int row, int col, int value) {
    for (int i = 0; i < 9; ++i) {
        // Check row and column
        if (grid[row][i] == value || grid[i][col] == value)
            return false;

        // Check 3x3 sub-grid
        int subRow = 3 * (row / 3) + i / 3;
        int subCol = 3 * (col / 3) + i % 3;
        if (grid[subRow][subCol] == value)
            return false;
    }
    return true;
}

bool solveSudoku(vector<vector<int>>& grid, int row = 0, int col = 0) {
    if (row == 9) return true;             // Finished all rows
    if (col == 9) return solveSudoku(grid, row + 1, 0);  // Move to next row
    if (grid[row][col] != 0) return solveSudoku(grid, row, col + 1); // Skip filled cells

    for (int val = 1; val <= 9; ++val) {
        if (isPlacementValid(grid, row, col, val)) {
            grid[row][col] = val;
            if (solveSudoku(grid, row, col + 1))
                return true;
            grid[row][col] = 0; // backtrack
        }
    }
    return false; // No valid value found
}

void displayGrid(const vector<vector<int>>& grid) {
    for (const auto& row : grid) {
        for (int num : row)
            cout << num << " ";
        cout << endl;
    }
}

int main() {
    vector<vector<int>> sudoku(9, vector<int>(9));
    cout << "Enter the Sudoku grid (9x9) with 0 for empty cells:\n";
    for (auto& row : sudoku)
        for (int& cell : row)
            cin >> cell;

    if (solveSudoku(sudoku)) {
        cout << "\nSolved Sudoku:\n";
        displayGrid(sudoku);
    } else {
        cout << "\nNo solution exists for the given Sudoku.\n";
    }

    return 0;
}

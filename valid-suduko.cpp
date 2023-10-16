#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    vector<unordered_set<char>> rows(9);
    vector<unordered_set<char>> columns(9);
    vector<unordered_set<char>> boxes(9);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            char cell = board[i][j];
            if (cell == '.') continue;

            // Check the row.
            if (rows[i].count(cell) > 0) return false;
            rows[i].insert(cell);

            // Check the column.
            if (columns[j].count(cell) > 0) return false;
            columns[j].insert(cell);

            // Check the 3x3 box.
            int boxIdx = (i / 3) * 3 + j / 3;
            if (boxes[boxIdx].count(cell) > 0) return false;
            boxes[boxIdx].insert(cell);
        }
    }

    return true;
}

int main() {
    // Example usage:
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    bool result = isValidSudoku(board);
    if (result) {
        cout << "The Sudoku board is valid." << endl;
    } else {
        cout << "The Sudoku board is not valid." << endl;
    }

    return 0;
}

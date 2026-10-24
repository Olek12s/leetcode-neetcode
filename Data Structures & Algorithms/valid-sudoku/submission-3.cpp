
class Solution {
public:

    // Rows & Cols cannot contain duplicates
    // Each of the 3x3 sub-boxes must contain the digits 1-9, also withotu duplicates
    bool isValidSudoku(vector<vector<char>>& board) {

        // Check if there are any row duplicates
        for (int i = 0; i < 9; i++) {
            std::unordered_set<char> row;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                if (!row.contains(board[i][j])) {
                    row.insert(board[i][j]);
                }
                else return false;
            }
        }

        // Check if there are any col duplicates
        for (int i = 0; i < 9; i++) {
            std::unordered_set<char> col;
            for (int j = 0; j < 9; j++) {
                if (board[j][i] == '.') continue;
                if (!col.contains(board[j][i])) {
                    col.insert(board[j][i]);
                }
                else return false;
            }
        }

        // Check for duplicates each of the 3x3 sub-boxes
        for (int subR = 0; subR < 3; subR++) {
            for (int subC = 0; subC < 3; subC++) {
                std::unordered_set<char> box;

                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        char val = board[subR * 3 + i][subC * 3 + j];

                        if (val == '.') continue;

                        if (!box.contains(val)) {
                            box.insert(val);
                        }
                        else return false;
                    }
                }
            }
        }
        return true;    // valid sudoku
    }
};
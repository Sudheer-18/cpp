class Solution {
public:
    // map<char, int> mp; 
  class Solution {
public:
    // map<char, int> mp; 
    bool Grid_Valid(vector<vector<char>>& board, int s, int e, char val) {
        for (int i = s; i < s + 3; i++) {
            for (int j = e; j < e + 3; j++) {
                if (board[i][j] == val) return false;
            }
        }
        return true;
    }
    bool Valid(int s, int e, vector<vector<char>>& board, char val) {
        for (int i = 0; i < 9; i++) {
            if (board[s][i] == val) return false;
        } 
        for (int i = 0; i < 9; i++) {
            if (board[i][e] == val) return false;
        }
        if (!Grid_Valid(board, s - s % 3, e - e % 3, val)) return false;
        return true;
    }

    bool solveSudokuHelper(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char val = '1'; val <= '9'; val++) {
                        if (Valid(i, j, board, val)) {
                            board[i][j] = val; 
                            if (solveSudokuHelper(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;  
                }
            }
        }
        return true;  
    }

    void solveSudoku(vector<vector<char>>& board) {
        solveSudokuHelper(board);
    }
};


    bool solveSudokuHelper(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char val = '1'; val <= '9'; val++) {
                        if (Valid(i, j, board, val)) {
                            board[i][j] = val; 
                            if (solveSudokuHelper(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;  
                }
            }
        }
        return true;  
    }

    void solveSudoku(vector<vector<char>>& board) {
        solveSudokuHelper(board);
    }
};

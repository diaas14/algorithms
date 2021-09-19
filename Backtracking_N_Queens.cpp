/**
 * Question:
 * The n-queens puzzle is the problem of placing n queens on an 
 * n x n chessboard such that no two queens attack each other.
 * Given an integer n, return all distinct solutions to the n-queens puzzle. 
 * You may return the answer in any order.
 * Each solution contains a distinct board configuration of the n-queens' placement, 
 * where 'Q' and '.' both indicate a queen and an empty space, respectively.
 */ 

class Solution {
public:
    vector<vector<string>> solutions;
    
    bool isValidMove(vector<string>& board, int row, int col) {
        for (int i=row-1; i>=0; i--)
            if (board[i][col] == 'Q') return false;
        for (int i=row-1, j=col-1; i>=0 && j>=0; i--, j--) 
            if (board[i][j] == 'Q') return false;
        for (int i=row-1, j=col+1; i>=0 && j<board.size(); i--, j++) 
            if (board[i][j] == 'Q') return false;
        return true;
    }
    
    // dfs
    void NQueens(vector<string>& board, int row) {
        if (row == board.size()) {
            solutions.push_back(board);
            return;
        }
        for (int i=0; i<board.size(); i++) {
            if (isValidMove(board, row, i)) {
                board[row][i] = 'Q';
                NQueens(board, row + 1);
                board[row][i] = '.';
            }  
        }   
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        NQueens(board, 0);
        return solutions;
    }
};

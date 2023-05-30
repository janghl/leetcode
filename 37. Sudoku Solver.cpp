class Solution {
public:
bool label = false;
bool available(vector<vector<char>>& board, int row, int col, int num) {
    for (int i = 0; i < 9 ; i++)
        if (num == board[row][i])
            return false;
    for (int i = 0; i < 9 ; i++)
        if (num == board[i][col])
            return false;
    for (int i = row / 3 * 3; i < row / 3 * 3 + 3; i++)
        for (int j = col / 3 * 3; j < col / 3 * 3 + 3; j++)
            if (board[i][j] == num)
                return false;
    return true;
}
void solveSudoku(vector<vector<char>>& board, int row = 0, int col = 0, int lastrow = 0, int lastcol = 0) {
    if (row == 0 && col == 0)
    {
        lastrow = 8;
        lastcol = 8;
        while (board[lastrow][lastcol] != '.') {
            if (lastcol == 0) {
                lastcol = 8;
                lastrow--;
            }
            else
                lastcol--;
        }
    }
    if ('.' != board[row][col]) {
        if (col == 8)
            solveSudoku(board, row + 1, 0, lastrow, lastcol);
        else
            solveSudoku(board, row, col + 1, lastrow, lastcol);
        return;
    }
    bool flag;
    for (int num = 1 + '0'; num <= 9 + '0'; num++) {
        if (available(board, row, col, num)) {
            if (row == lastrow && col == lastcol) {
                board[row][col] = num;
                label = true;
                return;
            }
            //cout << "row " << row << "col " << col << "num " << (char)num << endl;
            board[row][col] = num;
            if (col == 8)
                solveSudoku(board, row + 1, 0, lastrow, lastcol);
            else
                solveSudoku(board, row, col + 1, lastrow, lastcol);
            if (!label)
                board[row][col] = '.';

        }
    }
    return;
}
};

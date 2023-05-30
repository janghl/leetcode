class Solution {
public:
int arr[9] = { 0 };
int label = 0;
int totalNQueens(int n, int row = 0, int count = 0) {
    for (int col = 0; col < n; col++) {
        for (int i = 0; i < row; i++)
            if (arr[i] == col || i + arr[i] == row + col || row - i == col - arr[i]) {
                label = 1;
                break;
            }
        if (label == 1) {
            label = 0;
            continue;
        }
        if (row == n - 1) {
            /*for (int i = 0; i < n; i++)
            cout << "arr " << i << " = " << arr[i] << "\n";*/
            return count + 1;
        }
        arr[row] = col;
        count = totalNQueens(n, row + 1, count);
        arr[row] = -1;
    }
    return count;
}
};

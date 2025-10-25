#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<string> &board, int row, int col, int n)
{
    for (int i = 0; i < n; i++)
        if (board[i][col] == 'Q')
            return false;

    for (int i = 0; i < n; i++)
        if (board[row][i] == 'Q')
            return false;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q')
            return false;

    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 'Q')
            return false;

    return true;
}

void nQueen(vector<string> &board, int row, vector<vector<string>> &ans, int n)
{
    if (row == n)
    {
        ans.push_back(board);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (isSafe(board, row, i, n))
        {
            board[row][i] = 'Q';
            nQueen(board, row + 1, ans, n);
            board[row][i] = '.';
        }
    }
}

int main()
{
    int n = 4;
    vector<string> board(n, string(n, '.'));
    vector<vector<string>> ans;

    nQueen(board, 0, ans, n);

    for (auto &solution : ans)
{
    for (auto &row : solution)
    {
        for (char c : row)
            cout << c << "  ";  // 👈 spaces between cells
        cout << endl;
    }
    cout << endl;
}
}
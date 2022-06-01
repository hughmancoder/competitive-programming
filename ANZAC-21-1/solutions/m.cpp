#include <bits/stdc++.h>
using namespace std;

bool goVer(vector<string> &board, int i, int j)
{
    bool moved = false;
    while (i + 1 < board.size() && board[i + 1][j] != 'o')
    {
        moved = true;
        board[i + 1][j] = '*';
        i++;
    }
    return moved;
}

bool goHo(vector<string> &board, int i, int j)
{
    int l = j;
    int r = j;
    bool moved = false;
    while (l - 1 >= 0 && board[i + 1][l] == 'o' && board[i][l - 1] == '.')
    {
        moved = true;
        board[i][l - 1] = '*';
        l--;
        goVer(board, i, l);
    }

    while (r + 1 < board[i].size() && board[i + 1][r] == 'o' && board[i][r + 1] == '.')
    {
        moved = true;
        board[i][r + 1] = '*';
        r++;
        goVer(board, i, r);
    }
    return moved;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> board;
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        board.push_back(temp);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == '*')
            {
                goHo(board, i, j);
                goVer(board, i, j);
            }
        }
    }
    for (auto i : board)
    {
        cout << i << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

// Time Complexity O(r*c)
// Space Complexity O(r*c)

int main()
{
    int r;
    int c;
    int y;
    cin >> r >> c >> y;
    vector<string> board;
    
    // Create the board
    for (int i = 0; i < r; i++)
    {
        string temp;
        cin >> temp;
        board.push_back(temp);
    }

    vector<string> ret;

    // Just simulate it lol
    for (int i = 0; i < r; i++)
    {

        string temp = "";

        // this is for the vase where once you fold the right half over, it doesnt cover the entirety of the left half
        // therefore you just tkae the value from the left half
        for (int j = 0; j < c - (c - y)*2; j++)
        {
            temp.push_back(board[i][j]);
        }

        // for the right half, if there is no hole there is no hole
        // if there is a hole, there must be 2 holes
        for (int j = c - 1; j >= y; j--)
        {
            if (board[i][j] == 'x')
            {
                temp.push_back('x');
            }
            else
            {
                // probabbly a better way to do this, but I just used a whiteboard and worked it out
                int index = j - ((j - y) * 2 + 1);
                if (index >= 0)
                {
                    if (board[i][index] == 'o')
                        temp.push_back('o');
                    else
                        temp.push_back('x');
                }
                else
                    temp.push_back('o');
            }
        }
        ret.push_back(temp);
    }

    for (int i = 0; i < r; i++)
    {
        cout << ret[i] << endl;
    }
    return 0;
}
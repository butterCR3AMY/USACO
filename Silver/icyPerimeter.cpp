#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, mark[1000][1000], curA, curP, ansA, ansP;
string board[1000];
void go(int r, int c)
{
    mark[r][c] = 1;
    curP += 4;
    curA++;
    //check ones around it
    if (r-1 >= 0 && board[r-1][c] == '#')
    {
        curP--;
        if (!mark[r-1][c])
            go(r-1, c);
    }
    if (r+1 < n && board[r+1][c] == '#')
    {
        curP--;
        if (!mark[r+1][c])
            go(r+1, c);
    }
    if (c-1 >= 0 && board[r][c-1] == '#')
    {
        curP--;
        if (!mark[r][c-1])
            go(r, c-1);
    }
    if (c+1 < n && board[r][c+1] == '#')
    {
        curP--;
        if (!mark[r][c+1])
            go(r, c+1);
    }
}
int main()
{
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> board[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == '#' && !mark[i][j])
            {
                curP = 0;
                curA = 0;
                go(i, j);
                if (ansA == curA)
                    ansP = min(ansP, curP);
                else if (curA > ansA)
                {
                    ansA = curA;
                    ansP = curP;
                }
            }
        }
    }
    cout << ansA << " " << ansP;
}

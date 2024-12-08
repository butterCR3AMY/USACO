#include <iostream>
#include <algorithm>
using namespace std;

int cur, n, p, val1, val2, big, small, x[200000], y[200000], x1, y1, x2, y2, board[1001][1001];
int main()
{
    cin >> n >> p;
    for (int i = 0; i < p; i++)
        cin >> x[i] >> y[i];
    for (int ind = 1; ind <= p; ind++)
    {
        x1 = x[(ind-1)%p];
        y1 = y[(ind-1)%p];
        x2 = x[ind%p];
        y2 = y[ind%p];
        if (x1 <= x2 && y1 <= y2)
        {
            for (int i = x1; i <= x2; i++)
            {
                for (int j = y1; j <= y2; j++)
                {
                    board[i][j] = cur;
                    if (i == x2 && j == y2)
                        continue;
                    cur++;
                }
            }
        }
        else if (x1 >= x2 && y1 <= y2)
        {
            for (int i = x1; i >= x2; i--)
            {
                for (int j = y1; j <= y2; j++)
                {
                    board[i][j] = cur;
                    if (i == x2 && j == y2)
                        continue;
                    cur++;
                }
            }
        }
        else if (x1 >= x2 && y1 >= y2)
        {
            for (int i = x1; i >= x2; i--)
            {
                for (int j = y1; j >= y2; j--)
                {
                    board[i][j] = cur;
                    if (i == x2 && j == y2)
                        continue;
                    cur++;
                }
            }
        }
        else if (x1 <= x2 && y1 >= y2)
        {
            for (int i = x1; i <= x2; i++)
            {
                for (int j = y1; j >= y2; j--)
                {
                    board[i][j] = cur;
                    if (i == x2 && j == y2)
                        continue;
                    cur++;
                }
            }
        }
    }
    while(n--)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        big = max(board[x1][y1], board[x2][y2]);
        small = min(board[x1][y1], board[x2][y2]);
        val1 = big-small;
        val2 = cur-big+small;
        cout << min(val1, val2) << '\n';
    }
}

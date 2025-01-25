#include <iostream>
using namespace std;

int n, k, down, cur, visited[100][10], di[4] = {0, 0, -1, 1}, dj[4] = {-1, 1, 0, 0};
bool change = true;;
char board[100][10], board2[100][10];
void reset()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 10; j++)
            visited[i][j] = 0;
    }
}
void go(int x, int y)
{
    int x2, y2;
    visited[x][y] = 1;
    cur++;
    for (int i = 0; i < 4; i++)
    {
        x2 = x+di[i];
        y2 = y+dj[i];
        if (x2 >= 0 && x2 < n && y2 >= 0 && y2 < 10 && !visited[x2][y2] && board[x2][y2] == board[x][y])
            go(x2, y2);
    }
}
void zero()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (visited[i][j])
                board[i][j] = '0';
        }
    }
}
void fall()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 10; j++)
            board2[i][j] = '0';
    }
    for (int j = 0; j < 10; j++)
    {
        down = 0;
        for (int i = 0; i < n; i++)
        {
            if (board[i][j] != '0')
            {
                board2[down][j] = board[i][j];
                down++;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 10; j++)
            board[i][j] = board2[i][j];
    }
}
int main()
{
    freopen("mooyomooyo.in", "r", stdin);
    freopen("mooyomooyo.out", "w", stdout);
    cin >> n >> k;
    for (int i = n-1; i >= 0; i--)
    {
        for (int j = 0; j < 10; j++)
            cin >> board[i][j];
    }
    while (change)
    {
        change = false;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (board[i][j] == '0')
                    continue;
                reset();
                cur = 0;
                go(i, j);
                if (cur >= k)
                {
                    change = true;
                    zero();
                }
            }
        }
        fall();
    }
    for (int i = n-1; i >= 0; i--)
    {
        for (int j = 0; j < 10; j++)
            cout << board[i][j];
        cout << '\n';
    }
}

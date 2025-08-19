#include <iostream>
#include <queue>
#define f first
#define s second
using namespace std;

int n, x, y, nxtX, nxtY, xd[4] = {1, -1, 0, 0}, yd[4] = {0, 0, 1, -1}, neighbor[2050][2050], board[2050][2050], cnt;
queue<int> qx, qy;
void add(int x, int y)
{
    //see how all neighbor counts change if you add [x][y]
    board[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        nxtX = x+xd[i];
        nxtY = y+yd[i];
        if (nxtX >= 0 && nxtY >= 0 && nxtX < 2050 && nxtY < 2050 && board[nxtX][nxtY] == 1)
        {
            neighbor[nxtX][nxtY]++;
            neighbor[x][y]++;
            if (neighbor[nxtX][nxtY] == 3)
            {
                qx.push(nxtX);
                qy.push(nxtY);
            }
        }
    }
    if (neighbor[x][y] == 3)
    {
        qx.push(x);
        qy.push(y);
    }
}
void bfs()
{
    while(!qx.empty())
    {
        x = qx.front();
        qx.pop();
        y = qy.front();
        qy.pop();
        for (int i = 0; i < 4; i++)
        {
            nxtX = x+xd[i];
            nxtY = y+yd[i];
            if (nxtX >= 0 && nxtY >= 0 && nxtX < 2050 && nxtY < 2050 && board[nxtX][nxtY] == 0)
            {
                add(nxtX, nxtY);
                cnt++;
            }
        }
    }
}
int main()
{
    cin >> n;
    while (n--)
    {
        cin >> x >> y;
        x += 1000;
        y += 1000;
        if (board[x][y] == 1)
        {
            cnt--;
            cout << cnt << '\n';
            continue;
        }
        board[x][y] = 1;
        add(x, y);
        bfs();
        cout << cnt << '\n';
    }
}

#include <iostream>
#include <queue>
using namespace std;

int n, q, x, y, curx, cury, cost, vert[1510], horiz[1510], val[1510][1510];
char board[1510][1510];
queue<int> qx, qy;
void fill(int i, int j, int v)
{
    qx.push(i);
    qy.push(j);
    while(!qx.empty())
    {
        curx = qx.front();
        qx.pop();
        cury = qy.front();
        qy.pop();
        if (curx > 0 && board[curx-1][cury] == 'D')
        {
            qx.push(curx-1);
            qy.push(cury);
            cost += v-val[curx-1][cury];
            val[curx-1][cury] = v;
        }
        if (cury > 0 && board[curx][cury-1] == 'R')
        {
            qx.push(curx);
            qy.push(cury-1);
            cost += v-val[curx][cury-1];
            val[curx][cury-1] = v;
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
        cin >> vert[i];
    }
    for (int i = 0; i < n; i++)
        cin >> horiz[i];
    //find og cost
    for (int i = 0; i < n; i++)
    {
        //goes into vert[i]
        if (board[i][n-1] == 'R')
        {
            val[i][n-1] = vert[i];
            cost += vert[i];
            fill(i, n-1, vert[i]);
        }
    }
    for (int j = 0; j < n; j++)
    {
        if (board[n-1][j] == 'D')
        {
            val[n-1][j] = horiz[j];
            cost += horiz[j];
            fill(n-1, j, horiz[j]);
        }
    }
    cout << cost << '\n';
    cin >> q;
    while (q--)
    {
        cin >> x >> y;
        x--;
        y--;
        if (board[x][y] == 'R')
        {
            board[x][y] = 'D';
            if (x == n-1)
            {
                cost += horiz[y]-val[x][y];
                val[x][y] = horiz[y];
                fill(x, y, horiz[y]);
            }
            else
            {
                cost += val[x+1][y]-val[x][y];
                val[x][y] = val[x+1][y];
                fill(x, y, val[x+1][y]);
            }
        }
        else if (board[x][y] == 'D')
        {
            board[x][y] = 'R';
            if (y == n-1)
            {
                cost += vert[x]-val[x][y];
                val[x][y] = vert[x];
                fill(x, y, vert[x]);
            }
            else
            {
                cost += val[x][y+1]-val[x][y];
                val[x][y] = val[x][y+1];
                fill(x, y, val[x][y+1]);
            }
        }
        cout << cost << '\n';
    }
}

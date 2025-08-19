#include <iostream>
#include <queue>
using namespace std;

int n, bfs[2010][2010], u[2010][2010], l[2010][2010], r[2010][2010], d[2010][2010], x, y, cur;
string s;
queue<int> qx, qy;
int main()
{
    freopen("gates.in", "r", stdin);
    freopen("gates.out", "w", stdout);
    cin >> n >> s;
    x = 1002;
    y = 1002;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'N')
        {
            r[x-1][y] = 1;
            l[x][y] = 1;
            y++;
        }
        else if (s[i] == 'E')
        {
            u[x][y-1] = 1;
            d[x][y] = 1;
            x++;
        }
        else if (s[i] == 'S')
        {
            r[x-1][y-1] = 1;
            l[x][y-1] = 1;
            y--;
        }
        else if (s[i] == 'W')
        {
            u[x-1][y-1] = 1;
            d[x-1][y] = 1;
            x--;
        }
    }
    for (int i = 0; i < 2010; i++)
    {
        for (int j = 0; j < 2010; j++)
        {
            if (bfs[i][j] == 0)
            {
                cur++;
                bfs[i][j] = 1;
                qx.push(i);
                qy.push(j);
                while(!qx.empty())
                {
                    x = qx.front();
                    qx.pop();
                    y = qy.front();
                    qy.pop();
                    if (x > 0 && !bfs[x-1][y] && !l[x][y])
                    {
                        qx.push(x-1);
                        qy.push(y);
                        bfs[x-1][y] = 1;
                    }
                    if (y > 0 && !bfs[x][y-1] && !d[x][y])
                    {
                        qx.push(x);
                        qy.push(y-1);
                        bfs[x][y-1] = 1;
                    }
                    if (x < 2009 && !bfs[x+1][y] && !r[x][y])
                    {
                        qx.push(x+1);
                        qy.push(y);
                        bfs[x+1][y] = 1;
                    }
                    if (y < 2009 && !bfs[x][y+1] && !u[x][y])
                    {
                        qx.push(x);
                        qy.push(y+1);
                        bfs[x][y+1] = 1;
                    }
                }
            }
        }
    }
    cout << cur-1;
}

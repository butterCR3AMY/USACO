#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int row, c, a, b, ans, n, k, R, x1, y1, x2, y2, x, y, nxtx, nxty, xd[4] = {1, -1, 0, 0}, yd[4] = {0, 0, -1, 1}, board[101][101], xs[101], ys[101];
queue<int> qx, qy, qX, qY;
vector<bool> has[11010];
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("countcross.in", "r", stdin);
    freopen("countcross.out", "w", stdout);
    cin >> n >> k >> R;
    for(int i = 0; i < 11010; i ++)
        has[i].resize(11010);
    for (int i = 0; i < R; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        has[x1*101+y1][x2*101+y2] = has[x2*101+y2][x1*101+y1] = 1;
    }
    for (int i = 0; i < k; i++)
    {
        cin >> x1 >> y1;
        xs[i] = x1;
        ys[i] = y1;
    }
    for (int z = 0; z < k; z++)
    {
        for (int w = 0; w < k; w++)
        {
            row = xs[z];
            c = ys[z];
            a = xs[w];
            b = ys[w];
            if (z >= w)
                continue;
            while (!qx.empty())
                qx.pop();
            while (!qy.empty())
                qy.pop();
            qx.push(row);
            qy.push(c);
            qX.push(row);
            qY.push(c);
            board[row][c] = 1;
            while (!qx.empty())
            {
                x = qx.front();
                qx.pop();
                y = qy.front();
                qy.pop();
                for (int l = 0; l < 4; l++)
                {
                    nxtx = x+xd[l];
                    nxty = y+yd[l];
                    if (nxtx > 0 && nxtx <= n && nxty > 0 && nxty <= n && !board[nxtx][nxty] && !has[x*101+y][nxtx*101+nxty])
                    {
                        qx.push(nxtx);
                        qy.push(nxty);
                        qX.push(nxtx);
                        qY.push(nxty);
                        board[nxtx][nxty] = 1;
                        if (nxtx == a && nxty == b)
                            break;
                    }
                }
            }
            if (!board[a][b])
                ans++;
            while (!qX.empty())
            {
                x = qX.front();
                qX.pop();
                y = qY.front();
                qY.pop();
                board[x][y] = 0;
            }
        }
    }
    cout << ans << '\n';
}

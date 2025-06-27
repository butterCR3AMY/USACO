#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define s second
#define f first
using namespace std;

int ans, n, m, x, y, curx, cury, nxtx, nxty, a, b, adjx, adjy, mark[101][101], xd[4] = {1, -1, 0, 0}, yd[4] = {0, 0, 1, -1};
vector<pair<int, int>> nxt[101][101];
queue<int> qx, qy;
int main()
{
    freopen("lightson.in","r", stdin);
    freopen("lightson.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> a >> b;
        nxt[x][y].push_back({a,b});
    }
    mark[1][1] = 2;
    qx.push(1);
    qy.push(1);
    while (!qx.empty())
    {
        curx = qx.front();
        qx.pop();
        cury = qy.front();
        qy.pop();
        for (int j = 0; j < 4; j++)
        {
            adjx = curx+xd[j];
            adjy = cury+yd[j];
            if (adjx > 0 && adjy > 0 && adjx <= n && adjy <= n && mark[adjx][adjy] == 1)
            {
                mark[adjx][adjy] = 2;
                qx.push(adjx);
                qy.push(adjy);
            }
        }
        for (int i = 0; i < nxt[curx][cury].size(); i++)
        {
            nxtx = nxt[curx][cury][i].f;
            nxty = nxt[curx][cury][i].s;
            if (mark[nxtx][nxty] != 2)
            {
                mark[nxtx][nxty] = 1;
                //turn 2
                for (int j = 0; j < 4; j++)
                {
                    adjx = nxtx+xd[j];
                    adjy = nxty+yd[j];
                    if (adjx > 0 && adjy > 0 && adjx <= n && adjy <= n && mark[adjx][adjy] == 2)
                    {
                        mark[nxtx][nxty] = 2;
                        qx.push(nxtx);
                        qy.push(nxty);
                    }
                }
            }
        }
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
            if (mark[i][j] == 2 || mark[i][j] == 1)
                ans++;
    }
    cout << ans;
}

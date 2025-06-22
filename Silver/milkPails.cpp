#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int x, y, k, m, mini, cur, curx, cury, nxtx, nxty, bfs[101][101];
queue<int> qx, qy, q;
int main()
{
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
    cin >> x >> y >> k >> m;
    mini = 200;
    bfs[0][0] = 1;
    qx.push(0);
    qy.push(0);
    q.push(0);
    while (!qx.empty())
    {
        cur = q.front();
        q.pop();
        curx = qx.front();
        qx.pop();
        cury = qy.front();
        qy.pop();
        mini = min(mini, abs(m-(curx+cury)));
        if (cur == k)
            continue;
        //fill either pail
        if (!bfs[x][cury])
        {
            qx.push(x);
            qy.push(cury);
            q.push(cur+1);
            bfs[x][cury] = 1;
        }
        if (!bfs[curx][y])
        {
            qx.push(curx);
            qy.push(y);
            q.push(cur+1);
            bfs[curx][y] = 1;
        }
        //empty either pail
        if (!bfs[0][cury])
        {
            qx.push(0);
            qy.push(cury);
            q.push(cur+1);
            bfs[0][cury] = 1;
        }
        if (!bfs[curx][0])
        {
            qx.push(curx);
            qy.push(0);
            q.push(cur+1);
            bfs[curx][0] = 1;
        }
        //pour contents x -> y
        nxty = min(y, cury+curx);
        nxtx = curx-(nxty-cury);
        if (!bfs[nxtx][nxty])
        {
            qx.push(nxtx);
            qy.push(nxty);
            q.push(cur+1);
            bfs[nxtx][nxty] = 1;
        }
        //pour contents y -> x
        nxtx = min(x, curx+cury);
        nxty = cury-(nxtx-curx);
        if (!bfs[nxtx][nxty])
        {
            qx.push(nxtx);
            qy.push(nxty);
            q.push(cur+1);
            bfs[nxtx][nxty] = 1;
        }
    }
    cout << mini;
}

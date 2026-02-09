#include <iostream>
#include <queue>
#include <set>
using namespace std;

int n, arr[250][250], bfs[250][250], bfs2[250][250], cur, val, cnt, maxi1, maxi2, vali[62510], num[62510], vis[62510];
int xd[4] = {-1, 1, 0, 0}, yd[4] = {0, 0, -1, 1}, nxtR, nxtC;
int id1, id2;
vector<int> ones;
queue<int> qr, qc;
bool two;
set<int> adj[62510];

bool inBound(int x, int y)
{
    if (x >= 0 && x < n && y >= 0 && y < n)
        return true;
    return false;
}
void floodfill(int r, int c)
{
    qr.push(r);
    qc.push(c);
    while (!qr.empty())
    {
        r = qr.front();
        qr.pop();
        c = qc.front();
        qc.pop();
        for (int i = 0; i < 4; i++)
        {
            nxtR = r+xd[i];
            nxtC = c+yd[i];
            if (inBound(nxtR, nxtC) && (!bfs[nxtR][nxtC] || two))
            {
                if (arr[nxtR][nxtC] == val)
                {
                    if ((two && !bfs2[nxtR][nxtC]) || !two)
                    {
                        cnt++;
                        bfs[nxtR][nxtC] = cur;
                        if (two)
                            bfs2[nxtR][nxtC] = 1;
                        qr.push(nxtR);
                        qc.push(nxtC);
                    }
                }
                else if (two)
                {
                    adj[cur].insert(bfs[nxtR][nxtC]);
                }
            }
        }
    }
}
void floodfill2(int pos)
{
    for (int j : adj[pos])
    {
        if ((vali[j] == id1 || vali[j] == id2) && !vis[j])
        {
            vis[j] = 1;
            ones.push_back(j);
            cnt += num[j];
            floodfill2(j);
        }
    }
}
void reset()
{
    while (ones.size() > 0)
    {
        vis[ones.back()] = 0;
        ones.pop_back();
    }
}
int main()
{
    freopen("multimoo.in", "r", stdin);
    freopen("multimoo.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    }
    two = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (bfs[i][j] != 0)
                continue;
            cur++;
            bfs[i][j] = cur;
            val = arr[i][j];
            cnt = 1;
            floodfill(i, j);
            num[cur] = cnt;
            vali[cur] = val;
        }
    }
    two = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (vis[bfs[i][j]])
                continue;
            vis[bfs[i][j]] = 1;
            val = arr[i][j];
            cur = bfs[i][j];
            floodfill(i, j);
        }
    }
    cur = bfs[n-1][n-1];
    for (int i = 1; i <= cur; i++)
        vis[i] = 0;
    for (int i = 1; i <= cur; i++)
        maxi1 = max(maxi1, num[i]);
    for (int i = 1; i <= cur; i++)
    {
        if (num[cur] == 0)
            continue;
        id1 = vali[i];
        for (int j : adj[cur])
        {
            cnt = num[i];
            id2 = vali[j];
            vis[i] = 1;
            ones.push_back(i);
            floodfill2(i);
            reset();
            maxi2 = max(maxi2, cnt);
        }
        if (maxi2 == n*n)
            break;
    }
    cout << maxi1 << '\n' << maxi2;
}

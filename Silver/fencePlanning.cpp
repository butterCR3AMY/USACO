#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, a, b, ans, cur, minX, maxX, minY, maxY, x[100000], y[100000], vis[100000];
vector<int> nxt[100000];
queue<int> q;
int main()
{
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        nxt[a-1].push_back(b-1);
        nxt[b-1].push_back(a-1);
    }
    ans = 400000000;
    for (int i = 0; i < n; i++)
    {
        if (vis[i])
            continue;
        vis[i] = 1;
        q.push(i);
        minX = x[i];
        maxX = x[i];
        minY = y[i];
        maxY = y[i];
        while (!q.empty())
        {
            cur = q.front();
            q.pop();
            minX = min(minX, x[cur]);
            maxX = max(maxX, x[cur]);
            minY = min(minY, y[cur]);
            maxY = max(maxY, y[cur]);
            for (int j = 0; j < nxt[cur].size(); j++)
            {
                if (!vis[nxt[cur][j]])
                {
                    vis[nxt[cur][j]] = 1;
                    q.push(nxt[cur][j]);
                }
            }
        }
        ans = min(ans, 2*(maxY-minY)+2*(maxX-minX));
    }
    cout << ans;
}

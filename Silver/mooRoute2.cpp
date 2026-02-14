#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, c, r, d, s, nxt, arrTime, dfs[200010], a[200010];
vector<vector<pair<int, pair<int, int>>>> adj(200010);
void go(int cur, int t)
{
    while(adj[cur].size() > 0 && adj[cur].back().first >= t) //can leave through that one
    {
        nxt = adj[cur].back().second.first;
        arrTime = adj[cur].back().second.second;
        if (dfs[nxt] == -1)
            dfs[nxt] = arrTime;
        else
            dfs[nxt] = min(dfs[nxt], arrTime);
        adj[cur].pop_back();
        go(nxt, arrTime+a[nxt]);
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> c >> r >> d >> s;
        adj[c].push_back({r, {d, s}});
    }
    for (int i = 1; i <= n; i++)
    {
        dfs[i] = -1;
        if (adj[i].size())
            sort(adj[i].begin(), adj[i].end());
        cin >> a[i];
    }
    dfs[1] = 0;
    go(1, 0);
    for (int i = 1; i <= n; i++)
        cout << dfs[i] << '\n';
}

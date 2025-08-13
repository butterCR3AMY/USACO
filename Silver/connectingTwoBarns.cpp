#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

long long t, n, m, x, y, cur, dist1, dist2, dist, low, bfs[100010];
long long mini;
vector<long long> connect[100010], comps[100010], curC;
vector<vector<long long>> component;
queue<long long> q;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 0; i <= n; i++)
        {
            connect[i].clear();
            comps[i].clear();
            bfs[i] = -1;
        }
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            connect[x].push_back(y);
            connect[y].push_back(x);
        }
        component.clear();
        for (int i = 1; i <= n; i++)
        {
            if (bfs[i] != -1)
                continue;
            bfs[i] = i;
            q.push(i);
            curC.clear();
            curC.push_back(i);
            while(!q.empty())
            {
                cur = q.front();
                q.pop();
                for (int j = 0; j < connect[cur].size(); j++)
                {
                    if (bfs[connect[cur][j]] != i)
                    {
                        bfs[connect[cur][j]] = i;
                        curC.push_back(connect[cur][j]);
                        q.push(connect[cur][j]);
                    }
                }
            }
            sort(curC.begin(), curC.end());
            component.push_back(curC);
        }
        for (int i = 1; i <= n; i++)
            comps[bfs[i]].push_back(i);
        if (bfs[1] == bfs[n])
        {
            cout << 0 << '\n';
            continue;
        }
        mini = (long long)2e18;
        for (int i = 0; i < component.size(); i++)
        {
            //travel via component[i] to get from 1 to n
            dist1 = (int)1e9;//minDist from 1 to component[i]
            dist2 = (int)1e9;//minDist from component[i] to n
            //find dist1
            for (int j = 0; j < component[i].size(); j++)
            {
                low = (int)(lower_bound(comps[bfs[1]].begin(), comps[bfs[1]].end(), component[i][j])-comps[bfs[1]].begin());
                if (low < comps[bfs[1]].size())
                    dist1 = min(dist1, abs(comps[bfs[1]][low]-component[i][j]));
                if (low > 0)
                    dist1 = min(dist1, abs(component[i][j]-comps[bfs[1]][low-1]));
            }
            //find dist2
            for (int j = 0; j < component[i].size(); j++)
            {
                low = (int)(lower_bound(comps[bfs[n]].begin(), comps[bfs[n]].end(), component[i][j])-comps[bfs[n]].begin());
                if (low < comps[bfs[n]].size())
                    dist2 = min(dist2, abs(comps[bfs[n]][low]-component[i][j]));
                if (low > 0)
                    dist2 = min(dist2, abs(component[i][j]-comps[bfs[n]][low-1]));
            }
            mini = min((long long)(dist1*dist1+dist2*dist2), mini);
        }
        cout << mini << '\n';
    }
}

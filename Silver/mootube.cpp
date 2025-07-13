#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, t, a, b, r, k, cur, curR, cnt, curCnt, vis[5010], rel[5010][5010], low;
vector<int> con[5010];
vector<pair<int, int>> adj[5010];
queue<int> q, qr, visq;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    cin >> n >> t;
    for (int i = 0; i < n; i++)
        con[i].resize(n);
    for (int i = 0; i < n-1; i++)
    {
        cin >> a >> b >> r;
        adj[a-1].push_back({b-1, r});
        adj[b-1].push_back({a-1, r});
        rel[a-1][b-1] = r;
        rel[b-1][a-1] = r;
        con[a-1][b-1] = r;
        con[b-1][a-1] = r;
    }
    for (int i = 0; i < n-1; i++)
    {
        //go from i to all other vids and find relevance
        vis[i] = 1;
        visq.push(i);
        q.push(i);
        qr.push((int)1e9);
        cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (con[i][j] == 0)
                cnt++;
        }
        curCnt = 0;
        while(!q.empty() && curCnt < cnt)
        {
            cur = q.front();
            q.pop();
            curR = qr.front();
            qr.pop();
            if (cur == i)
                con[i][cur] = 0;
            else if (con[i][cur] == 0)
            {
                curCnt++;
                con[i][cur] = curR;
                con[cur][i] = curR;
            }
            for (auto p : adj[cur])
            {
                int j = p.first;
                if (rel[cur][j] && !vis[j])
                {
                    vis[j] = 1;
                    visq.push(j);
                    qr.push(min(curR, rel[cur][j]));
                    q.push(j);
                }
            }
        }
        while(!visq.empty())
        {
            cur = visq.front();
            visq.pop();
            vis[cur] = 0;
        }
    }
    for (int i = 0; i < n; i++)
        sort(con[i].begin(), con[i].end());
    for (int i = 0; i < t; i++)
    {
        cin >> k >> a;
        low = (int)(lower_bound(con[a-1].begin(), con[a-1].end(), k)-con[a-1].begin());
        cout << n-low << '\n';
    }
}

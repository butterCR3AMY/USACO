#include <iostream>
#include <map>
#include <vector>
#include <queue>
#define f first
#define s second
using namespace std;

int n, a, b, m, ans, cur, bfs[100010];
char c;
vector<pair<int, char>> connect[100010];
queue<int> q;
int main()
{
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> c >> a >> b;
        connect[a].push_back({b, c});
        connect[b].push_back({a, c});
    }
    for (int i = 1; i <= n; i++)
    {
        if (bfs[i] != 0)
            continue;
        ans++;
        bfs[i] = 1;
        q.push(i);
        while(!q.empty())
        {
            cur = q.front();
            q.pop();
            for (int j = 0; j < connect[cur].size(); j++)
            {
                if (bfs[connect[cur][j].f] == 0)
                {
                    if (connect[cur][j].s == 'S')
                        bfs[connect[cur][j].f] = bfs[cur];
                    else
                        bfs[connect[cur][j].f] = 3-bfs[cur];
                    q.push(connect[cur][j].f);
                }
                else
                {
                    if (connect[cur][j].s == 'S' && bfs[cur] != bfs[connect[cur][j].f])
                    {
                        cout << 0;
                        return 0;
                    }
                    else if (connect[cur][j].s == 'D' && bfs[cur] == bfs[connect[cur][j].f])
                    {
                        cout << 0;
                        return 0;
                    }
                }
            }
        }
    }
    cout << 1;
    for (int i = 0; i < ans; i++)
        cout << 0;
}

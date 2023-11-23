#include <iostream>
#include <vector>
#include <queue>
#define input() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int n, m, a, b, sol[100000], cnt = 0, cur, ans[100000];
vector<vector<int>> adj;
vector<int> cur1;
queue<int> q;
char c;
string farms;
int main()
{
    input();
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
    cin >> n >> m;
    cin >> farms;
    cur1.push_back(0);
    for (int i = 0; i < n; i++)
    {
        cur1[0] = i;
        adj.push_back(cur1);
    }
    for (int i = 0; i < n-1; i++)
    {
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    for (int i = 0; i < n; i++)
    {
        if (sol[i])
            continue;
        q.push(i);
        cnt ++;
        while (!q.empty())
        {
            cur = q.front();
            q.pop();
            if (sol[cur])
                continue;
            sol[cur] = cnt;
            for (int j = 0; j < adj[cur].size(); j++)
            {
                if (farms[adj[cur][j]] == farms[cur])
                {
                    q.push(adj[cur][j]);
                }
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        a--;
        b--;
        if (sol[a] == sol[b] && farms[a] != c)
        {
            cout << '0';
            continue;
        }
        cout << '1';
    }
}

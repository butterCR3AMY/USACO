#include <iostream>
#include <vector>
#include <queue>
using namespace std;

long long n, a, b, cur, cnt, ans, bfs[100010];
vector<long long> connection[100010];
queue<long long> q;
int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        connection[a].push_back(b);
        connection[b].push_back(a);
        bfs[i] = -1;
    }
    bfs[n] = -1;
    bfs[1] = 0;
    q.push(1);
    while(!q.empty())
    {
        cur = q.front();
        q.pop();
        cnt = 1;
        for (int i = 0; i < connection[cur].size(); i++)
        {
            if (bfs[connection[cur][i]] == -1)
            {
                q.push(connection[cur][i]);
                bfs[connection[cur][i]] = bfs[cur]+1;
                cnt++;
            }
        }
        cur = 1;
        while(cur < cnt)
        {
            cur *= 2;
            ans++;
        }
    }
    cout << ans+n-1;
}

#include <iostream>
#include <map>
#include <vector>
#include <queue>
#define f first
#define s second
using namespace std;

long long n, a, b, ni, di, bfs[200010], cur, nxt, ans, mini;
map<long long, long long> num, pos;
vector<long long> connect[200010], comp, compNum;
pair<long long, long long> id[200010];
queue<long long> q;
int main()
{
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++)
    {
        cin >> id[i].s >> id[i].f;
        bfs[i] = -1;
        num[id[i].f] = id[i].s;
        pos[id[i].f] = i;
    }
    for (int i = 0; i < n; i++)
    {
        if (a-id[i].f >= 0 && a-id[i].f != id[i].f && num[a-id[i].f] > 0)
            connect[i].push_back(pos[a-id[i].f]);
        if (a != b && b-id[i].f >= 0 && b-id[i].f != id[i].f && num[b-id[i].f] > 0)
            connect[i].push_back(pos[b-id[i].f]);
    }
    for (int i = 0; i < n; i++)
    {
        if (bfs[i] != -1)
            continue;
        if (connect[i].size() == 2)
            continue;
        comp.clear();
        comp.push_back(i);
        q.push(i);
        bfs[i] = 1;
        while (!q.empty())
        {
            cur = q.front();
            q.pop();
            for (int j = 0; j < connect[cur].size(); j++)
            {
                nxt = connect[cur][j];
                bfs[nxt] = 1;
                if (nxt == comp[comp.size()-2])
                    continue;
                comp.push_back(nxt);
                q.push(nxt);
                break;
            }
        }
        compNum.clear();
        for (int j = 0; j < comp.size(); j++)
            compNum.push_back(id[comp[j]].s);
        for (int j = 0; j < compNum.size()-1; j++)
        {
            //look at comp[j] going into comp[j+1]
            ni = compNum[j];
            mini = min(ni, compNum[j+1]);
            ans += mini;
            compNum[j] -= mini;
            compNum[j+1] -= mini;
        }
        for (int j = 0; j < comp.size(); j++)
        {
            di = id[comp[j]].f;
            if (di*2 == a || di*2 == b)
                ans += compNum[j]/2;
        }
    }
    cout << ans;
}

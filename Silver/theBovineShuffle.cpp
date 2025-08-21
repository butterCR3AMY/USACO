#include <iostream>
#include <vector>
using namespace std;

int n, nxt[100010], bfs[100010], cur, curr, ans, past, repeat;
vector<int> path;
bool cycle;
int main()
{
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> nxt[i];
    curr = 1;
    for (int i = 1; i <= n; i++)
    {
        if (bfs[i] != 0)
            continue;
        bfs[i] = curr;
        cur = i;
        path.clear();
        path.push_back(cur);
        cycle = true;
        while(true)
        {
            if (bfs[nxt[cur]] == 0)
            {
                bfs[nxt[cur]] = curr;
                path.push_back(nxt[cur]);
                cur = nxt[cur];
            }
            else if (bfs[nxt[cur]] == curr)
            {
                repeat = nxt[cur];
                break;
            }
            else
            {
                repeat = nxt[cur];
                cycle = false;
                break;
            }
        }
        curr++;
        if (!cycle)
            continue;
        for (int i = 0; i < path.size(); i++)
        {
            if (path[i] == repeat)
            {
                past = i;
                break;
            }
        }
        ans += path.size()-past;
    }
    cout << ans;
}

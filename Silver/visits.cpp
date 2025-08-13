#include <iostream>
using namespace std;

long long n, moo[100010], nxt[100010], bfs[100010], ans, maxi, mini, total, cur, start;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> nxt[i] >> moo[i];
        nxt[i]--;
        maxi = max(maxi, moo[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (bfs[i] != 0)
            continue;
        total = moo[i];
        bfs[i] = i+1;
        cur = i;
        while(true)
        {
            if (bfs[nxt[cur]] == 0)
            {
                total += moo[nxt[cur]];
                bfs[nxt[cur]] = i+1;
                cur = nxt[cur];
            }
            else
            {
                start = nxt[cur];
                break;
            }
        }
        if (bfs[start] != i+1)
        {
            ans += total;
            continue;
        }
        mini = moo[start];
        cur = start;
        while(true)
        {
            if (nxt[cur] == start)
                break;
            else
            {
                mini = min(mini, moo[nxt[cur]]);
                cur = nxt[cur];
            }
        }
        ans += total-mini;
    }
    cout << ans;
}

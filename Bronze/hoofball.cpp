#include <iostream>
#include <algorithm>
using namespace std;

int n, cow[100], nxt[100], mark[1001], ans, cur;
int main()
{
    freopen("hoofball.in", "r", stdin);
    freopen("hoofball.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> cow[i];
    sort(cow, cow+n);
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            nxt[i] = 1;
        else if (i == n-1)
            nxt[i] = n-2;
        else if (cow[i]-cow[i-1] <= cow[i+1]-cow[i])
            nxt[i] = i-1;
        else
            nxt[i] = i+1;
    }
    //simulation --> flow
    for (int i = 0; i < n; i++)
    {
        if (mark[i] == 1 || nxt[i] < i || nxt[nxt[i]] == i)
            continue;
        ans++;
        cur = i;
        while (mark[cur] == 0)
        {
            mark[cur] = 1;
            cur = nxt[cur];
        }
    }
    //simulation <-- flow
    for (int i = n-1; i >= 0; i--)
    {
        if (mark[i] == 1 || nxt[i] > i)
            continue;
        ans++;
        cur = i;
        while (mark[cur] == 0)
        {
            mark[cur] = 1;
            cur = nxt[cur];
        }
    }
    cout << ans;
}

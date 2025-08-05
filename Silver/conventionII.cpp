#include <iostream>
#include <algorithm>
#include <queue>
#define f first
#define s second
typedef long long ll;
using namespace std;

ll n, pos, t, ans;
pair<ll, pair<ll, ll>> range[100010], cur;
priority_queue<pair<ll, pair<ll, ll>>> q;
bool comp(pair<ll, pair<ll, ll>> p1, pair<ll, pair<ll, ll>> p2)
{
    return p1.s.f < p2.s.f;
}
int main()
{
    freopen("convention2.in", "r", stdin);
    freopen("convention2.out", "w", stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> range[i].s.f >> range[i].s.s;
        range[i].f = n-i;
    }
    sort(range, range+n, comp);
    q.push(range[0]);
    pos = 1;
    while (!q.empty())
    {
        cur = q.top();
        q.pop();
        ans = max(ans, t-cur.s.f);
        t = max(t, cur.s.f);
        t += cur.s.s;
        while (pos < n)
        {
            if (pos < n && range[pos].s.f <= t)
                q.push(range[pos]);
            else
                break;
            pos++;
        }
        if (q.empty())
        {
            if (pos < n)
                q.push(range[pos]);
            pos++;
        }
    }
    cout << ans;
}

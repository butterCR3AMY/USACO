#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define f first
#define s second
#define ll long long
using namespace std;

ll n, dist, dir[500010], curW, curT, w, pos, ans;
pair<ll, pair<ll, ll>> xwi[500010];
pair<ll, ll> tim[500010];
vector<pair<ll, ll>> l, r;
queue<ll> q;
bool comp(pair<ll, pair<ll, ll>> p1, pair<ll, pair<ll, ll>> p2)
{
    return p1.s.s < p2.s.s;
}
int main()
{
    freopen("meetings.in", "r", stdin);
    freopen("meetings.out", "w", stdout);
    cin >> n >> dist;
    for (int i = 0; i < n; i++)
    {
        cin >> xwi[i].s.f >> xwi[i].f >> dir[i];
        xwi[i].s.s = i;
        w += xwi[i].s.f;
        if (dir[i] == -1)
            l.push_back({xwi[i].f, i});
        else
            r.push_back({xwi[i].f, i});
    }
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    //calculate times for each
    for (int i = 0; i < l.size(); i++)
    {
        tim[i].f = l[i].f;
        tim[i].s = i;
    }
    for (int i = l.size(); i < n; i++)
    {
        tim[i].f = dist-r[i-l.size()].f;
        tim[i].s = i;
    }
    sort(tim, tim+n);
    sort(xwi, xwi+n);
    //find time needed for w/2
    for (int i = 0; i < n; i++)
    {
        curW += xwi[tim[i].s].s.f;
        curT = tim[i].f;
        pos = i;
        if (w%2)
        {
            if (curW > w/2)
                break;
        }
        else
        {
            if (curW >= w/2)
                break;
        }
    }
    //calculate the collisions till & include T
    sort(xwi, xwi+n);
    for (int i = 0; i < n; i++)
    {
        pos = xwi[i].s.s;
        if (dir[pos] == -1)
        {
            while (!q.empty() && xwi[i].f-q.front() > 2*curT)
            {
                q.pop();
            }
            ans += q.size();
        }
        else
        {
            q.push(xwi[i].f);
        }
    }
    cout << ans << '\n';
}

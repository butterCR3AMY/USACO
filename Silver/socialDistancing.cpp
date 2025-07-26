#include <iostream>
#include <algorithm>
#define f first
#define s second
typedef long long ll;
using namespace std;

ll n, m, cnt, pos, cur;
pair<ll, ll> range[100010];
ll bs(ll l, ll r)
{
    ll mid;
    while (l < r)
    {
        mid = (l+r)/2;
        //try out w dist mid between all of em
        cnt = 1;
        pos = 0;
        cur = range[0].f;
        while (pos < m)
        {
            cur += mid;
            while (pos < m && cur > range[pos].s)
                pos++;
            cur = max(cur, range[pos].f);
            if (cur > range[pos].s)
                break;
            cnt++;
            if (cnt >= n)
                break;
        }
        if (cnt < n)
            r = mid-1;
        else if (r == l+1)
        {
            //check if r works
            cnt = 1;
            pos = 0;
            cur = range[0].f;
            while (pos < m)
            {
                cur += r;
                while (pos < m && cur > range[pos].s)
                    pos++;
                cur = max(cur, range[pos].f);
                if (cur > range[pos].s)
                    break;
                cnt++;
                if (cnt >= n)
                    break;
            }
            if (cnt >= n)
                return r;
            return l;
        }
        else
            l = mid;
    }
    return l;
}
int main()
{
    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> range[i].f >> range[i].s;
    sort(range, range+m);
    cout << bs(1, (range[m-1].s-range[0].f)/(n-1)) << '\n';
}

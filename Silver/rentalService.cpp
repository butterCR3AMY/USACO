#include <iostream>
#include <algorithm>
#define f first
#define s second
typedef long long ll;
using namespace std;

ll n, m, r, maxi, cur, up, c[100010], rent[100010], pref[100010], prefixSums[100010], amount[100010];
pair<ll, ll> buy[100010];
bool comp (pair<ll, ll> p1, pair<ll, ll> p2)
{
    return p1.s > p2.s;
}
bool comp1 (ll x1, ll x2)
{
    return x1 > x2;
}
int main()
{
    freopen("rental.in", "r", stdin);
    freopen("rental.out", "w", stdout);
    cin >> n >> m >> r;
    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 0; i < m; i++)
        cin >> buy[i].f >> buy[i].s;
    for (int i = 0; i < r; i++)
        cin >> rent[i];
    sort(c, c+n, comp1);
    sort(buy, buy+m, comp);
    sort(rent, rent+r, comp1);
    prefixSums[0] = buy[0].f;
    amount[0] = buy[0].f*buy[0].s;
    for (int i = 1; i < m; i++)
    {
        prefixSums[i] = prefixSums[i-1]+buy[i].f;
        amount[i] = amount[i-1]+buy[i].f*buy[i].s;
    }
    pref[0] = rent[0];
    for (int i = 1; i < r; i++)
        pref[i] = pref[i-1]+rent[i];
    maxi = max(pref[min(r,n)-1], maxi);
    for (int i = 0; i < n; i++)
    {
        cur += c[i];
        up = (long long)(upper_bound(prefixSums, prefixSums+m, cur)-prefixSums);
        up--;
        if (up == m-1)
        {
            if (i == n-1)
                maxi = max(maxi, amount[up]);
            else
                maxi = max(maxi, amount[up]+pref[min(r-1, n-2-i)]);
        }
        else
        {
            if (i == n-1)
                maxi = max(maxi, amount[up]+buy[up+1].s*(cur-prefixSums[up]));
            else
                maxi = max(maxi, amount[up]+buy[up+1].s*(cur-prefixSums[up])+pref[min(r-1, n-2-i)]);
        }
    }
    cout << maxi;
}

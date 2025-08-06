#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#define f first
#define s second
using namespace std;

int n, g, num, d, c, id, maxi, maxi2, cur, ans;
pair<int, pair<int, int>> m[100010];
multiset<int> ms;
map<int, int> ma;
int main()
{
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);
    cin >> n >> g;
    for (int i = 0; i < n; i++)
    {
        cin >> m[i].f >> m[i].s.f >> m[i].s.s;
        ma[m[i].s.f] = g;
        ms.insert(g);
    }
    sort(m, m+n);
    for (int i = 0; i < n; i++)
    {
        d = m[i].f;
        id = m[i].s.f;
        c = m[i].s.s;
        maxi = *prev(ms.end());
        maxi2 = *prev(prev(ms.end()));
        cur = ma[id];
        if (cur == maxi && cur+c > maxi && maxi == maxi2)
            ans++;
        else if (cur == maxi && cur+c <= maxi2)
            ans++;
        else if (cur < maxi && cur+c >= maxi)
            ans++;
        ms.erase(ms.find(cur));
        ms.insert(cur+c);
        ma[id] = cur+c;
    }
    cout << ans;
}

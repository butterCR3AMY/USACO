#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#define f first
#define s second
using namespace std;

int n, ans, hi, low;
pair<string, string> flip;
string city, state, first2;
vector<pair<string, string>> p;
int main()
{
    freopen("citystate.in", "r", stdin);
    freopen("citystate.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> city >> state;
        first2 = "";
        first2 += city[0];
        first2 += city[1];
        p.push_back({first2, state});
    }
    sort(p.begin(), p.end());
    for (int i = 0; i < n; i++)
    {
        flip.f = p[i].s;
        flip.s = p[i].f;
        if (p[i].f < p[i].s)
        {
            low = lower_bound(p.begin(), p.end(), flip)-p.begin();
            hi = upper_bound(p.begin(), p.end(), flip)-p.begin();
            ans += hi-low;
        }
    }
    cout << ans;
}

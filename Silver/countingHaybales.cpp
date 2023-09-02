#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, q, cur, a, b, up, lb;
vector<int> acorns;
int main()
{
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> cur;
        acorns.push_back(cur);
    }
    sort(acorns.begin(), acorns.end());
    for (int t = 0; t < q; t++)
    {
        cin >> a >> b;
        lb = lower_bound(acorns.begin(), acorns.end(), a)-acorns.begin();
        up = upper_bound(acorns.begin(), acorns.end(), b)-acorns.begin();
        cout << up-lb << endl;
    }
}

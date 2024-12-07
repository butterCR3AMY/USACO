#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, q, v, s, c[200000], diff[200000], t[200000], ind;
int main()
{
    cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> t[i];
    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 0; i < n; i++)
        diff[i] = t[i]-c[i];
    sort(diff, diff+n);
    while(q--)
    {
        cin >> v >> s;
        ind = upper_bound(diff, diff+n, s)-diff;
        if (n-ind >= v)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
}

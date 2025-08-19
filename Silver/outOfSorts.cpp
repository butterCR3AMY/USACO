#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int n, a[100010], after[100010], compressed[100010], ans;
bool works;
map<int, int> used;
int main()
{
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        after[i] = a[i];
    }
    sort(after, after+n);
    for (int i = 0; i < n; i++)
    {
        compressed[i] = (int)(lower_bound(after, after+n, a[i])-after)+used[a[i]];
        used[a[i]]++;
    }
    for (int i = 0; i < n; i++)
        ans = max(ans, i-compressed[i]);
    cout << ans+1;
}

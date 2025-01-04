#include <iostream>
#include <algorithm>
using namespace std;

int n, w[100000], cur, ans;
int main()
{
    freopen("lemonade.in", "r", stdin);
    freopen("lemonade.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> w[i];
    sort(w, w+n);
    for (int i = n-1; i >= 0; i--)
    {
        if (i == n-1)
        {
            cur++;
            ans++;
        }
        else if (w[i] >= cur)
        {
            cur++;
            ans++;
        }
    }
    cout << ans;
}

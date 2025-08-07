#include <iostream>
#include <algorithm>
using namespace std;

int n, a[100010], maxi, mini, up, low;
int main()
{
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a+n);
    //find maxi
    if (a[1]-a[0] < a[n-1]-a[n-2])
        maxi = 1+a[n-1]-n-a[1]+1;
    else
        maxi = 1+a[n-2]-(a[0]+n-1);
    //look at x...x+n-1
    mini = n*100;
    for (int i = 0; i < n; i++)
    {
        up = upper_bound(a, a+n, a[i]+n-1)-a;
        if (a[i]+n-1 > a[n-1])
            continue;
        if (a[i]+n-1 > a[n-2] && a[i]+n-1 < a[n-1] && i == 0)
            continue;
        mini = min(mini, n-(up-i));
    }
    cout << mini << '\n' << maxi;
}

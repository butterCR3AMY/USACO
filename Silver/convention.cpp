//#define THIS
#ifdef THIS
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

int n, m, c;
int arr[100010];
int bs(int l, int r)
{
    if (l == r)
        return l;
    int mid = (l+r)/2;
    int groups = 1, prev = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - arr[prev] > mid)
            prev = i, groups++;
        if (i-prev+1 > c)
            prev = i, groups++;
    }
    if (groups > m)
        return bs(mid+1, r);
    return bs(l, mid);
}
int main()
{
    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);
    cin >> n >> m >> c;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr+n);
    cout << bs(0, 1e9) << '\n';
}
#endif

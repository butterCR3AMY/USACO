#include <iostream>
#include <algorithm>
using namespace std;

int i, j, n, k, diamonds[50000], bfor[50000], after[50000], maxi, maxi1, maxi2;
int main()
{
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    cin >> n >> k;
    for (int x = 0; x < n; x++)
        cin >> diamonds[x];
    sort(diamonds, diamonds+n);
    i = 0;
    j = 0;
    while (i < n && j < n)
    {
        if (diamonds[j]-diamonds[i] > k)
            i++;
        else
        {
            after[i] = max(after[i], j-i+1);
            bfor[j] = max(bfor[j], j-i+1);
            j++;
        }
    }
    maxi = after[n-1];
    for (int x = n-1; x >= 0; x--)
    {
        maxi = max(maxi, after[x]);
        after[x] = maxi;
    }
    maxi = bfor[0];
    for (int x = 0; x < n; x++)
    {
        maxi = max(maxi, bfor[x]);
        bfor[x] = maxi;
    }
    for (int div = 1; div < n; div++)
        maxi = max(maxi, bfor[div-1]+after[div]);
    cout << maxi;
}

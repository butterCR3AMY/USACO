#include <iostream>
using namespace std;

long long n, t, d1, d2, a[1000010], prefixSums[1000010], b, e, elsie, total;
int main()
{
    cin >> t;
    while(t--)
    {
        cin >> n;
        total = 0;
        for (int i = 0; i < n; i++)
            prefixSums[i] = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            total += a[i];
            if (i == 0)
                prefixSums[i] = a[i];
            else
                prefixSums[i] = prefixSums[i-1]+a[i];
        }
        b = prefixSums[n/2];
        for (int i = 0; i < n/2-1; i++)
            b = min(b, prefixSums[i+n/2+1]-prefixSums[i]);
        e = total-b;
        cout << b << " " << e << '\n';
    }
}

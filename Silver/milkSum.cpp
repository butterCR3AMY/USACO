#include <iostream>
#include <algorithm>
using namespace std;

long long n, q, cur, up, pos, a[150010], b[150010], prefixSums[150010], og, ai, j;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b, b+n);
    og = b[0];
    prefixSums[0] = b[0];
    for (int i = 1; i < n; i++)
    {
        og += b[i]*(i+1);
        prefixSums[i] = prefixSums[i-1]+b[i];
    }
    cin >> q;
    while(q--)
    {
        cin >> ai >> j;
        ai--;
        if (a[ai] == j)
            cout << og << '\n';
        else if (a[ai] > j)
        {
            cur = og;
            cur -= a[ai]*((int)(lower_bound(b, b+n, a[ai])-b)+1);
            up = (int)(upper_bound(b, b+n, j)-b);
            pos = (int)(lower_bound(b, b+n, a[ai])-b);
            //up to pos-1 are shifted up
            cur += j*(up+1);
            if (up == 0)
                cur += prefixSums[pos-1];
            else
                cur += prefixSums[pos-1]-prefixSums[up-1];
            cout << cur << '\n';
        }
        else
        {
            cur = og;
            cur -= a[ai]*((int)(lower_bound(b, b+n, a[ai])-b)+1);
            up = (int)(upper_bound(b, b+n, j)-b);
            pos = (int)(lower_bound(b, b+n, a[ai])-b);
            //pos+1 to up-1 shifted down
            cur += j*(up);
            cur -= prefixSums[up-1]-prefixSums[pos];
            cout << cur << '\n';
        }
    }
}

#include <iostream>
#include <algorithm>
using namespace std;

int maxN = 100010;
int n, k, mid, acorns[100010], cnt, endX, lo, hi, res;

int valid(int r)
{
    cnt = 1;
    endX = acorns[0]+2*r;
    for (int i = 0; i < n; i++)
    {
        if (acorns[i] > endX)
        {
            cnt ++;
            if (cnt > k)
                return false;
            endX = acorns[i]+2*r;
        }
    }
    return true;
}


int main()
{
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> acorns[i];
    }
    sort(acorns, acorns+n);
    lo = 1;
    hi = 1e9;
    res = -1;
    
    while (lo <= hi)
    {
        mid = (lo+hi)/2;
        if (valid(mid))
        {
            res = mid;
            hi = mid-1;
        }
        else
        {
            lo = mid+1;
        }
    }
    cout << res << endl;
}

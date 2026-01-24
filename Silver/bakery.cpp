#include <iostream>
#include <cmath>
using namespace std;

long long t, n, num, dem, cookie, muffin, a[100], b[100], c[100], lowBound, hiBound;
long long doDiv(long long num, long long dem)
{
    if (dem < 0)
        return (long long)ceil(static_cast<double>(num)/dem);
    else
        return (long long)floor(static_cast<double>(num)/dem);
}
long long binSearch(long long low, long long hi)
{
    long long k;
    //bounds of x (y = k-x)
    while (low < hi)
    {
        k = (low+hi)/2;
        lowBound = 0;
        hiBound = cookie-1;
        for (int i = 0; i < n; i++)
        {
            //find range of x from cur
            if (b[i]-a[i] > 0)
            {
                //x <= (c[i]+b[i]*k-a*cookie-b*muffin)/(b-a)
                num = c[i]+b[i]*k-a[i]*cookie-b[i]*muffin;
                dem = b[i]-a[i];
                //do hiBound
                hiBound = min(hiBound, doDiv(num, dem));
            }
            else if (b[i]-a[i] < 0)
            {
                //x >= (c[i]+b[i]*k-a*cookie-b*muffin)/(b-a)
                num = c[i]+b[i]*k-a[i]*cookie-b[i]*muffin;
                dem = b[i]-a[i];
                //do lowBound
                lowBound = max(lowBound, doDiv(num, dem));
            }
            else
            {
                //if c[i]+b[i]*(k-cookie-muffin) < 0
                if ((c[i]+b[i]*(k-cookie-muffin)) < 0) //impossible
                {
                    low = k+1;
                    break;
                }
            }
        }
        if (low == k+1)
            continue;
        if (lowBound > hiBound)
            low = k+1;
        else if (k-hiBound >= muffin)
            low = k+1;
        else if (k-lowBound < 0)
            low = k+1;
        else
            hi = k;
    }
    return low;
}
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> cookie >> muffin;
        for (int i = 0; i < n; i++)
            cin >> a[i] >> b[i] >> c[i];
        cout << binSearch(0, cookie+muffin-2) << '\n';
    }
}

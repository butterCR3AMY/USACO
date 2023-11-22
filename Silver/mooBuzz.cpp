#include <iostream>
#include <vector>
using namespace std;

long long n;
long long binarySearch(long long target)
{
    long long low = 0, high = 1e10, mid, pos; //declare the variables
    while(low < high)
    {
        mid = (low+high)/2;
        pos = (mid-mid/3-mid/5+mid/15);
        if (mid%3 == 0 || mid%5 == 0 || mid%15 == 0)
        {
            if (pos >= target)
                high --;
            else
                low ++;
        }
        else
        {
            if (pos > target)
                high = mid-1;
            else if (pos < target)
                low = mid+1;
            else
                return mid;
        }
    }
    return low;
}
signed main()
{
    freopen("moobuzz.in", "r", stdin);
    freopen("moobuzz.out", "w", stdout);
    cin >> n;
    cout << binarySearch(n);
}

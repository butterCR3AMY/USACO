#include <iostream>
#include <vector>
using namespace std;
#define int long long

long long k;
int n, x, dist, dur, ans1, cnt, mini;
int addFrom(int a, int b)
{
    return (b-a+1)*(b+a)/2;
}
signed main()
{
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);
    cin >> k >> n;
    for (int t = 0; t < n; t++)
    {
        cin >> x;
        cnt = 0;
        ans1 = addFrom(1, x);
        if (ans1 >= k)
        {
            for (int i = 1; i <= x; i++)
            {
                cnt += i;
                if (cnt >= k)
                {
                    cout << i << endl;
                    break;
                }
            }
        }
        else
        {
            cnt = ans1;
            dist = cnt;
            dur = x;
            if ((k-dist)%x == 0)
                dur += (k-dist)/x;
            else
                dur += (k-dist)/x+1;
            for (int i = x+1; i <= k; i++)
            {
                cnt += i;
                dist = cnt + addFrom(x, i-1);
                if (dist > k)
                {
                    cout << dur << endl;
                    break;
                }
                dur = i+i-x;
                if ((k-dist)%i == 0)
                    dur += (k-dist)/i;
                else
                    dur += (k-dist)/i+1;
            }
        }
    }
}

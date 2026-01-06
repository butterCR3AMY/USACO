#include <iostream>
#include <algorithm>
using namespace std;

long long t, n, m, what, rem, num, curCnt, val, mini, preSum[200010], arr[200010];
int previ, cur;
int main()
{
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            arr[i] %= m;
        }
        sort(arr, arr+n);
        preSum[0] = arr[0];
        for (int i = 1; i < n; i++)
            preSum[i] = preSum[i-1]+arr[i];
        for (int i = 0; i < n; i++)
        {
            //calculate cur by adding diff ranges
            curCnt = 0;
            rem = arr[i];
            //wanna do m-rem+num (go to one to left) num < rem-m/2
            //do till lower_bound - 1
            cur = (int)(lower_bound(arr, arr+n, rem-m/2)-arr);
            cur--;
            //0 to cur is m-rem+num
            if (cur != -1)
            {
                val = (m-rem)*(cur+1);
                val += preSum[cur]; //for num
                curCnt += val;
            }
            previ = max(0, cur+1);
            //wanna do rem-num (go to cur from left) num < rem
            //do till lower_bound - 1
            cur = (int)(lower_bound(arr, arr+n, rem)-arr);
            cur--;
            //prev to cur is rem-num
            if (cur != -1 && previ <= cur)
            {
                val = (rem)*(cur-previ+1);
                if (previ == 0)
                    val -= preSum[cur]; //for num
                else
                    val -= preSum[cur]-preSum[previ-1];
                curCnt += val;
            }
            previ = max(0, cur+1);
            //wanna do num-rem (go to cur from right) num <= rem+m/2
            //do till upper_bound-1
            cur = (int)(upper_bound(arr, arr+n, rem+m/2)-arr);
            cur--;
            //prev to cur is num-rem
            if (cur != -1 && previ <= cur)
            {
                if (previ == 0)
                    val = preSum[cur]; //for num
                else
                    val = preSum[cur]-preSum[previ-1];
                val -= (rem)*(cur-previ+1);
                curCnt += val;
            }
            previ = max(0, cur+1);
            //wanna do m-num+rem (go to one to right) rest
            //prev to n-1 is m-num+rem
            val = (m+rem)*(n-1-previ+1);
            if (previ == 0)
                val -= preSum[n-1]; //for num
            else
                val -= preSum[n-1]-preSum[previ-1];
            curCnt += val;
            if (i == 0)
                mini = curCnt;
            mini = min(mini, curCnt);
        }
        cout << mini << '\n';
    }
}

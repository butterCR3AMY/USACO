#include <iostream>
using namespace std;

long long n, cur, arr[500][500], preSum[500], min101, min100;
bool zero;
long long go()
{
    long long ans = 0;
    for (int horiz = 0; horiz < n; horiz++)
    {
        for (int i = 0; i < n; i++)
            preSum[i] = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= horiz; j++)
            {
                if (arr[i][j] != 0)
                    preSum[j]++;
            }
            //deal w zeros
            zero = false;
            for (int j = horiz; j >= 0; j--)
            {
                if (arr[i][j] == 0)
                    zero = true;
                if (zero)
                    preSum[j] = 0;
            }
            cur = 0;
            for (int j = 0; j <= horiz; j++)
                cur += preSum[j];
            ans += cur;
        }
    }
    return ans;
}
int main()
{
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j< n; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] < 100)
                arr[i][j] = 0;
            else if (arr[i][j] == 100)
                arr[i][j] = 1;
            else
                arr[i][j] = 2;
        }
    }
    //find amount where min >= 100 (aka no < 100)
    min100 = go();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 1)
                arr[i][j] = 0;
        }
    }
    //find amount where min >= 101 (aka no <= 100)
    min101 = go();
    cout << min100-min101;
}

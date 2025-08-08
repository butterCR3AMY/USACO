#include <iostream>
#include <algorithm>
using namespace std;

long long n, k, x1, y1, x2, y2, cur, bfor[1010][1010], prefixSums[1010][1010], ans;
int main()
{
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        x2--;
        y2--;
        bfor[x1][y1]++;
        bfor[x2+1][y2+1]++;
        bfor[x1][y2+1]--;
        bfor[x2+1][y1]--;
    }
    //prefixSums of bfor is the array after
    for (int i = 0; i <= 1000; i++)
    {
        cur = 0;
        for (int j = 0; j <= 1000; j++)
        {
            cur += bfor[i][j];
            if (i == 0)
                prefixSums[i][j] = cur;
            else
                prefixSums[i][j] = cur+prefixSums[i-1][j];
            if (prefixSums[i][j] == k)
                ans++;
        }
    }
    
    cout << ans;
}

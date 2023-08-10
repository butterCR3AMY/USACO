#include <iostream>
#include <algorithm>
using namespace std;

int n, cows[30], stalls[30], cnt = 0;
long long ans = 1;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> cows[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> stalls[i];
    }
    sort(cows, cows+n, greater<int>());
    for (int i = 0; i < n; i++)
    {
        cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (stalls[j] >= cows[i])
                cnt ++;
        }
        ans *= (cnt-i);
    }
    cout << ans << endl;
}

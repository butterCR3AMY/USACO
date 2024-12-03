#include <iostream>
#include <algorithm>
using namespace std;

int n, og[100], sorted[100], cow[100], cur, cnt, last, ans = 1000;
bool isDone()
{
    for (int i = 0; i < n; i++)
        if (cow[i] != sorted[i])
            return false;
    return true;
}
int main()
{
    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> og[i];
        sorted[i] = og[i];
    }
    sort(sorted, sorted+n);
    for (int bessie = 0; bessie < n; bessie++)
    {
        for (int i = 0; i < n; i++)
            cow[i] = og[i];
        //start -> end (swapping backwards)
        cnt = 0;
        cur = bessie;
        last = cow[bessie];
        for (int i = bessie; i >= 0; i--)
        {
            if (i == bessie)
                continue;
            if (cow[i] > cow[cur] && cow[i] != last)
            {
                last = cow[i];
                swap(cow[i], cow[cur]);
                cur = i;
                cnt++;
            }
            if (cow[i] == last)
            {
                swap(cow[i], cow[cur]);
                cur = i;
            }
        }
        if (isDone())
            ans = min(ans, cnt);
        for (int i = 0; i < n; i++)
            cow[i] = og[i];
        //end -> start (swapping forwards)
        cnt = 0;
        cur = bessie;
        last = cow[bessie];
        for (int i = bessie; i < n; i++)
        {
            if (i == bessie)
                continue;
            if (cow[i] < cow[cur] && cow[i] != last)
            {
                last = cow[i];
                swap(cow[i], cow[cur]);
                cur = i;
                cnt++;
            }
            if (cow[i] == last)
            {
                swap(cow[i], cow[cur]);
                cur = i;
            }
        }
        if (isDone())
            ans = min(ans, cnt);
    }
    cout << ans;
}

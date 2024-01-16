//socdist2
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, x, s, h, minDiff = 1000010, maxR, ans = 1;
vector<int> healthy, sick, all;
int main()
{
    freopen("socdist2.in", "r", stdin);
    freopen("socdist2.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> s;
        if (s)
            sick.push_back(x);
        else
            healthy.push_back(x);
    }
    sort(sick.begin(), sick.end());
    s = sick.size();
    h = healthy.size();
    for (int i = 0; i < s; i++)
    {
        for (int j= 0; j < h; j++)
            minDiff = min(minDiff, abs(sick[i]-healthy[j]));
    }
    maxR = minDiff-1;
    for (int i = 0; i < s; i++)
    {
        if (i > 0)
        {
            if ((sick[i]-sick[i-1]) > maxR)
                ans++;
        }
    }
    cout << ans;
}

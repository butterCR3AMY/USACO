#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int t, n, k, prevH = -100010, prevG = -100010, patches;
string cur, ans;

int main()
{
    cin >> t;
    for (int q = 0; q < t; q++)
    {
        patches = 0;
        cin >> n >> k;
        cin >> cur;
        ans = "";
        prevH = -100010;
        prevG = -100010;
        for (int i = 0; i < n; i++)
        {
            ans += '.';
        }
        for (int i = 0; i < n; i++)
        {
            if (cur[i] == 'H')
            {
                if (abs(i-prevH) > k)
                {
                    prevH = min(i+k, n-1);
                    if (ans[prevH] == 'G')
                        ans[prevH-1] = 'H';
                    else
                        ans[prevH] = 'H';
                }
            }
            if (cur[i] == 'G')
            {
                if (abs(i-prevG) > k)
                {
                    prevG = min(i+k, n-1);
                    if (ans[prevG] == 'H')
                        ans[prevG-1] = 'G';
                    else
                        ans[prevG] = 'G';
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (ans[i] != '.')
                patches ++;
        }
        cout << patches << endl;
        cout << ans << endl;
    }
}

#include <iostream>
using namespace std;

int n, m, b, x[100], y[100], horizontal, vertical, q1, q2, q3, q4, ans = 1000;
int main()
{
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);
    cin >> n >> b;
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    //get vertical divider
    for (int v = 0; v < n; v++)
    {
        for (int diff = -1; diff <= 1; diff += 2)
        {
            //get horizontal divider
            for (int h = 0; h < n; h++)
            {
                for (int diff2 = -1; diff2 <= 1; diff2 += 2)
                {
                    vertical = y[v]+diff;
                    horizontal = x[h]+diff2;
                    q1 = 0;
                    q2 = 0;
                    q3 = 0;
                    q4 = 0;
                    for (int i = 0; i < n; i++)
                    {
                        if (x[i] > horizontal && y[i] > vertical)
                            q1++;
                        if (x[i] < horizontal && y[i] > vertical)
                            q2++;
                        if (x[i] < horizontal && y[i] < vertical)
                            q3++;
                        if (x[i] > horizontal && y[i] < vertical)
                            q4++;
                    }
                    m = max(max(q1, q2), max(q3, q4));
                    ans = min(ans, m);
                }
            }
        }
    }
    cout << ans;
}

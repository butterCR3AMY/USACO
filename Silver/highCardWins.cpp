#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, e[50000], cur, low, ans, mark[50000];
vector<int> b;
int main()
{
    freopen("highcard.in", "r", stdin);
    freopen("highcard.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> e[i];
    sort(e, e+n);
    for (int i = 1; i <= 2*n; i++)
    {
        if (i != e[cur])
            b.push_back(i);
        else if (i == e[cur])
            cur++;
    }
    for (int i = 0; i < n; i++)
    {
        low = lower_bound(b.begin(), b.end(), e[i])-b.begin();
        if (low != n)
        {
            if (!mark[low])
            {
                mark[low] = 1;
                ans++;
            }
            else
            {
                for (int j = low+1; j < n; j++)
                {
                    if (!mark[j])
                    {
                        mark[j] = 1;
                        ans++;
                        break;
                    }
                }
            }
        }
    }
    cout << ans;
}

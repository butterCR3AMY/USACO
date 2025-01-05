#include <iostream>
#include <utility>
#include <algorithm>
#define f first
#define s second
using namespace std;

int c, n, t[20000], mark[20000], b[20000], low, ans;
pair<int, int> cow[20000];
int main()
{
    freopen("helpcross.in", "r", stdin);
    freopen("helpcross.out", "w", stdout);
    cin >> c >> n;
    for (int i = 0; i < c; i++)
        cin >> t[i];
    for (int i = 0; i < n; i++)
        cin >> cow[i].s >> cow[i].f;
    sort(t, t+c);
    sort(cow, cow+n);
    for (int i = 0; i < n; i++)
        b[i] = cow[i].f;
    //assign cows to chickens
    for (int i = 0; i < c; i++)
    {
        //for chicken i find the cow that works w the smallest b
        low = int(lower_bound(b, b+n, t[i])-b);
        if (cow[low].s <= t[i] && !mark[low])
        {
            mark[low] = 1;
            ans++;
        }
        else
        {
            for (int j = low+1; j < n; j++)
            {
                if (cow[j].s <= t[i] && !mark[j])
                {
                    mark[j] = 1;
                    ans++;
                    break;
                }
            }
        }
    }
    cout << ans;
}

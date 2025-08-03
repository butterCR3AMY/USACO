#include <iostream>
#include <algorithm>
#define f first
#define s second
using namespace std;

long long n, l, j, rf, rb, cnt, last, after[100010], ind[100010];
pair<long long, long long> stop[100010];
int main()
{
    freopen("reststops.in", "r", stdin);
    freopen("reststops.out", "w", stdout);
    cin >> l >> n >> rf >> rb;
    for (int i = 0; i < n; i++)
        cin >> stop[i].f >> stop[i].s;
    sort(stop, stop+n);
    for (int i = n-1; i >= 0; i--)
    {
        if (i == n-1)
        {
            ind[i] = i;
            after[i] = stop[i].s;
        }
        else if (stop[i].s > after[i+1])
        {
            after[i] = stop[i].s;
            ind[i] = i;
        }
        else
        {
            after[i] = after[i+1];
            ind[i] = ind[i+1];
        }
    }
    j = ind[0];
    while (j < n)
    {
        if (j == n-1)
        {
            cnt += (rf-rb)*(stop[j].f-last)*stop[j].s;
            break;
        }
        cnt += (rf-rb)*(stop[j].f-last)*stop[j].s;
        last = stop[j].f;
        j = ind[j+1];
    }
    cout << cnt;
}

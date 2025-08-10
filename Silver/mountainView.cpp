#include <iostream>
#include <algorithm>
#define f first
#define s second
using namespace std;

int n, sums[100010], minAfter[100010], low, cnt;
pair<int, int> pos[100010];
bool comp (pair<int, int> p1, pair<int, int> p2)
{
    return p1.f+p1.s < p2.f+p2.s || (p1.f+p1.s == p2.f+p2.s && p1.s < p2.s);
}
int main()
{
    freopen("mountains.in", "r", stdin);
    freopen("mountains.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> pos[i].f >> pos[i].s;
    sort(pos, pos+n, comp);
    for (int i = 0; i < n; i++)
        sums[i] = pos[i].f+pos[i].s;
    for (int i = n-1; i >= 0; i--)
    {
        if (i == n-1)
            minAfter[i] = pos[i].f-pos[i].s;
        else
            minAfter[i] = min(minAfter[i+1], pos[i].f-pos[i].s);
    }
    for (int i = 0; i < n; i++)
    {
        //check for each if can be seen
        low = (int)(lower_bound(sums, sums+n, pos[i].f+pos[i].s)-sums);
        while(pos[low].s <= pos[i].s)
            low++;
        if (low < n && minAfter[low] <= pos[i].f-pos[i].s)
            cnt++;
    }
    cout << n-cnt;
}

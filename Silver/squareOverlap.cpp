#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#define f first
#define s second
using namespace std;

int n, k, x, y, ans;
long long overlap;
pair<int, int> lef, righ;
vector<pair<int, int>> side, l, r;
set<pair<int, int>> cur;
bool found;
int main()
{
    freopen("squares.in", "r", stdin);
    freopen("squares.out", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        lef.f = x-k/2;
        lef.s = y-k/2;
        righ.f = x+k/2;
        righ.s = y-k/2;
        side.push_back(lef);
        side.push_back(righ);
        l.push_back(lef);
        r.push_back(righ);
    }
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    sort(side.begin(), side.end());
    for (pair<int, int> p : side)
    {
        //curLine is p
        if (binary_search(r.begin(), r.end(), p))
        {
            //right side
            cur.erase({p.s, p.f-k});
            auto lowestWorks = cur.upper_bound({p.s-k, p.f});
            auto highestWorks = cur.lower_bound({p.s+k, p.f-k});
            if (highestWorks == cur.begin())
                continue;
            highestWorks = prev(highestWorks);
            if (highestWorks == cur.end() || lowestWorks == cur.end())
                continue;
            if (*highestWorks >= *lowestWorks)
            {
                overlap = (p.f-(*highestWorks).s)*(min((*highestWorks).f, p.s)+k-max((*highestWorks).f, p.s));
                if (*highestWorks > *lowestWorks)
                {
                    cout << -1;
                    return 0;
                }
                else if (found && overlap > 0)
                {
                    cout << -1;
                    return 0;
                }
                if (overlap)
                {
                    found = true;
                    ans = overlap;
                }
            }
        }
        else
            cur.insert({p.s, p.f});
    }
    cout << ans;
}

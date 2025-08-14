#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#define f first
#define s second
using namespace std;

int n, up, ogtl, ogtr, ogbl, ogbr, xbar, mini, numx[1000010], tl, tr, bl, br;
pair<int, int> pos[1000010];
vector<int> yx[1000010];
set<int> x, y;
int main()
{
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> pos[i].f >> pos[i].s;
        x.insert(pos[i].f);
        y.insert(pos[i].s);
        yx[pos[i].s].push_back(pos[i].f);
        numx[pos[i].f]++;
    }
    for (int i = 0; i < n; i++)
        sort(yx[pos[i].s].begin(), yx[pos[i].s].end());
    ogtl = 0;
    ogtr = 0;
    ogbl = 0;
    ogbr = n;
    mini = n;
    for (auto i:x)
    {
        xbar = i+1;
        ogbl += numx[i];
        ogbr -= numx[i];
        tl = ogtl;
        tr = ogtr;
        bl = ogbl;
        br = ogbr;
        //look at x = i+1 and y = j+1
        for (auto j:y)
        {
            //shift horiz bar to be below j
            up = (int)(upper_bound(yx[j].begin(), yx[j].end(), xbar)-yx[j].begin());
            tl += up;
            bl -= up;
            tr += yx[j].size()-up;
            br -= yx[j].size()-up;
            mini = min(max(max(tl, tr), max(bl, br)), mini);
        }
    }
    cout << mini;
}

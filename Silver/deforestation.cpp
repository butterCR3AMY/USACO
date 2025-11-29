#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
typedef long long ll;

ll n, k, q, l, r, t, ans, low, hi, cur, runningCnt, tree[100010];
vector<pair<int, int>> endpts;
set<pair<ll, pair<int, int>>> s;
map<pair<int, int>, ll> howMany, whatWas;
map<pair<int, int>, bool> seen;
pair<int, int> p;
int main()
{
    ios_base::sync_with_stdio();cin.tie(0);cout.tie(0);
    cin >> q;
    while (q--)
    {
        cin >> n >> k;
        ans = 0;
        for (int i = 0; i < n; i++)
            cin >> tree[i];
        sort(tree, tree+n);
        endpts.clear();
        howMany.clear();
        whatWas.clear();
        for (int i = 0; i < k; i++)
        {
            cin >> l >> r >> t;
            endpts.push_back({l, r+1});
            endpts.push_back({r+1, l});
            low = (int)(lower_bound(tree, tree+n, l)-tree);
            hi = (int)(upper_bound(tree, tree+n, r)-tree);
            howMany[{l, r+1}] = (hi-low)-t;
        }
        sort(endpts.begin(), endpts.end());
        s.clear();
        runningCnt = 0;
        ans = 0;
        cur = 0;
        for (int i = 0; i < n; i++) //go thru trees
        {
            while (cur < endpts.size() && tree[i] >= endpts[cur].first) //reached a pt where it matters
            {
                if (endpts[cur].first < endpts[cur].second) //left
                {
                    s.insert({howMany[endpts[cur]]+runningCnt, endpts[cur]});
                    whatWas[endpts[cur]] = runningCnt;
                }
                else if (endpts[cur].first == endpts[cur].second)
                {
                    if (seen[endpts[cur]])//right
                    {
                        p = {endpts[cur].second, endpts[cur].first};
                        s.erase({howMany[p]+whatWas[p], p});
                    }
                    else //left
                    {
                        s.insert({howMany[endpts[cur]]+runningCnt, endpts[cur]});
                        whatWas[endpts[cur]] = runningCnt;
                    }
                }
                else //right
                {
                    //look for thing in set w/ {l, r} & erase
                    p = {endpts[cur].second, endpts[cur].first};
                    s.erase({howMany[p]+whatWas[p], p});
                }
                cur++;
            }
            if (s.size() == 0)
                ans++;
            else
            {
                if (s.begin()->first-runningCnt > 0)
                {
                    ans++;
                    runningCnt++;
                }
            }
        }
        cout << ans << '\n';
    }
}

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#define f first
#define s second
using namespace std;

long long n, cnt, last, one[100010], type, num;
pair<long long, long long> range[100010], status[200010];
vector<long long> all;
map<long long, long long> m;
set<long long> cur;
int main()
{
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> range[i].f >> range[i].s;
        all.push_back(range[i].f);
        all.push_back(range[i].s);
    }
    sort(all.begin(), all.end());
    for (int i = 0; i < 2*n; i++)
        m[all[i]] = i;
    for (int i = 0; i < n; i++)
    {
        status[m[range[i].f]] = {1, i};
        status[m[range[i].s]] = {0, i};
    }
    for (int i = 0; i < 2*n; i++)
    {
        //all[i] happens
        type = status[i].f;
        num = status[i].s;
        if (type == 1 && cur.size() == 1)
            one[*cur.begin()] += all[i]-last;
        if (type == 0 && cur.size() == 1)
            one[*cur.begin()] += all[i]-last;
        else if (type == 1 && cur.size() == 0)
        {
            if (i > 0)
                cnt += all[i]-all[i-1];
            last = all[i];
        }
        else if (type == 0 && cur.size() == 2)
            last = all[i];
        if (type == 1)
            cur.insert(num);
        if (type == 0)
            cur.erase(num);
    }
    sort(one, one+n);
    cnt = all[2*n-1]-all[0]-cnt;
    cout << cnt-one[0];
}

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define f first
#define s second
using namespace std;

int n, pos[300010], cur;
long long ans;
set<int> s;
vector<int> v;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> cur;
        v.push_back(cur);
    }
    for (int i = 0; i < n; i++)
        pos[v[i]] = i;
    for (int i = n; i >= 1; i--)
    {
        auto it = s.insert(pos[i]).first;
        if (next(it) != s.end())
            ans += *next(it)-*it+1;
    }
    reverse(v.begin(), v.end());
    for (int i = 0; i < n; i++)
        pos[v[i]] = i;
    s.clear();
    for (int i = n; i >= 1; i--)
    {
        auto it = s.insert(pos[i]).first;
        if (next(it) != s.end())
            ans += *next(it)-*it+1;
    }
    cout << ans;
}

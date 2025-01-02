#include <iostream>
#include <vector>
using namespace std;

int n, x[200], y[200], p[200], mark[200], cnt, ans;
vector<int> reach[200];
void go(int cur)
{
    if (!mark[cur])
    {
        cnt++;
        mark[cur] = 1;
    }
    for (int i = 0; i < reach[cur].size(); i++)
    {
        if (!mark[reach[cur][i]])
            go(reach[cur][i]);
    }
}
int main()
{
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i] >> p[i];
    for (int i = 0; i < n; i++)
    {
        //see how many i can reach
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            //see if i can reach j
            if (p[i]*p[i] >= (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]))
                reach[i].push_back(j);
        }
    }
    for (int start = 0; start < n; start++)
    {
        //see how many a broadcast from start can reach
        cnt = 0;
        for (int i = 0; i < n; i++)
            mark[i] = 0;
        go(start);
        ans = max(ans, cnt);
    }
    cout << ans;
}

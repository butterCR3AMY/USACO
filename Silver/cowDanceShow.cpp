#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, tMax, d[10000], og[10000], cnt;
int go(int k)
{
    int t = 0, mini, cur, howMany;
    vector<int> stage, newStage;
    for (int i = 0; i < k; i++)
        stage.push_back(d[i]);
    cur = k;
    while (!stage.empty())
    {
        //find min
        mini = 100000;
        for (int i = 0; i < stage.size(); i++)
            mini = min(mini, stage[i]);
        t += mini;
        for (int i = 0; i < stage.size(); i++)
            stage[i] -= mini;
        newStage.clear();
        for (int i = 0; i < stage.size(); i++)
        {
            if (stage[i])
                newStage.push_back(stage[i]);
        }
        stage.clear();
        for (int i = 0; i < newStage.size(); i++)
            stage.push_back(newStage[i]);
        howMany = k-stage.size();
        for (int i = cur; i < min(n, cur+howMany); i++)
            stage.push_back(d[i]);
        cur += howMany;
    }
    return t;
}
int binSearch(int l, int r)
{
    int mid, t, pt, cur;
    while (l < r)
    {
        mid = (l+r)/2;
        //figure out time if u hav mid as k
        //simulate
        t = go(mid);
        for (int i = 0; i < n; i++)
            d[i] = og[i];
        if (t <= tMax)
            r = mid;
        else
            l = mid+1;
    }
    return l;
}
int main()
{
    freopen("cowdance.in", "r", stdin);
    freopen("cowdance.out", "w", stdout);
    cin >> n >> tMax;
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
        og[i] = d[i];
    }
    cout << binSearch(0, n);
}

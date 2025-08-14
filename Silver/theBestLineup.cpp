#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, t, a[200010], after[200010], maxi;
vector<int> ind, redid, ans;
void redo(int index)
{
    for (int i = 0; i < n; i++)
    {
        if (i == ind[index-1]+1)
            redid.push_back(a[ind[index]]);
        if (i == ind[index])
            continue;
        redid.push_back(a[i]);
    }
}
int main()
{
    cin >> t;
    while(t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            after[i] = 0;
        }
        ind.clear();
        after[n] = 0;
        after[n-1] = a[n-1];
        ind.push_back(n-1);
        ind.push_back(-1);
        for (int i = n-2; i >= 0; i--)
        {
            after[i] = after[i+1];
            if (a[i] >= after[i+1])
            {
                after[i] = a[i];
                ind.push_back(i);
            }
        }
        sort(ind.begin(), ind.end());
        redid.clear();
        for (int i = 0; i < ind.size(); i++)
        {
            if (i == 0)
                continue;
            maxi = 0;
            for (int j = ind[i-1]+1; j < ind[i]; j++)
                maxi = max(maxi, a[j]);
            if (maxi >= after[ind[i]+1])
            {
                //shift ind[i] back to ind[i-1]+1
                redo(i);
            }
        }
        ans.clear();
        ans.push_back(redid[n-1]);
        for (int i = n-2; i >= 0; i--)
        {
            if (redid[i] >= ans.back())
                ans.push_back(redid[i]);
        }
        reverse(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++)
        {
            if (i == ans.size()-1)
                cout << ans[i] << '\n';
            else
                cout << ans[i] << " ";
        }
    }
}

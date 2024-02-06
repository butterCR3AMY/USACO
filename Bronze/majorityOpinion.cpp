#include <iostream>
#include <set>
#include <vector>
using namespace std;

int n, cnt, t, arr[100000];
set<int> ans;
vector<int> res;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    for (int q = 0; q < t; q++)
    {
        cin >> n;
        ans.clear();
        res.clear();
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cnt = 1;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] != arr[i-1])
            {
                if (cnt > 1)
                {
                    ans.insert(arr[i-1]);
                }
                cnt = 0;
            }
            cnt++;
        }
        for (int i = 2; i < n; i++)
        {
            if (arr[i] == arr[i-2])
                ans.insert(arr[i]);
        }
        if (cnt > 1)
            ans.insert(arr[n-1]);
        for (int x:ans)
            res.push_back(x);
        for (int i = 0; i < res.size(); i++)
        {
            if (i == res.size()-1)
                cout << res[i];
            else
                cout << res[i] << ' ';
        }
        if (ans.size() == 0)
            cout << -1;
        cout << '\n';
    }
}

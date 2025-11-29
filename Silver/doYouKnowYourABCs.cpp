#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int n, t, arr[10];
vector<int> possible;
set<pair<int, pair<int, int>>> ans;
bool works(int a, int b, int c)
{
    bool yes;
    for (int i = 0; i < n; i++)
    {
        yes = false;
        //check each arr[i]
        if (arr[i] == a+b || arr[i] == b+c || arr[i] == a+c)
            yes = true;
        if (arr[i] == a || arr[i] == b || arr[i] == c)
            yes = true;
        if (arr[i] == a+b+c)
            yes = true;
        if (!yes)
            return false;
    }
    return true;
}
int main()
{
    cin >> t;
    while(t--)
    {
        cin >> n;
        ans.clear();
        possible.clear();
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            possible.push_back(arr[i]);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[i]-arr[j] > 0)
                    possible.push_back(arr[i]-arr[j]);
            }
        }
        for (int a:possible)
        {
            for (int b:possible)
            {
                for (int c:possible)
                {
                    if (a <= b && b <= c && works(a, b, c))
                        ans.insert({a, {b, c}});
                }
            }
        }
        cout << ans.size() << '\n';
    }
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k, cur, last, l, r, to, ans;
vector<int> a, jump;
int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> cur;
        a.push_back(cur);
    }
    sort(a.rbegin(), a.rend());
    //jump all the way back
    k--;
    last = (a[0]/12+1)*12;
    ans = last;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < last-12)
        {
            // to = first mult 12 > a[i]
            to = (a[i]/12+1)*12;
            jump.push_back(last-12-to);
            last = to;
        }
    }
    r = (a[n-1]/12)*12;
    jump.push_back(r);
    sort(jump.rbegin(), jump.rend());
    for (int i = 0; i < k; i++)
        ans -= jump[i];
    cout << ans;
}

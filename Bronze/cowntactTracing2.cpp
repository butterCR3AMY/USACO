// cowntact tracing 2
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int cnt, n, m, ans, R;
vector<int> segs, times;
string s;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
            cnt ++;
        if (i > 0 && s[i] == '0' && s[i-1] == '1')
        {
            segs.push_back(cnt);
            cnt = 0;
        }
    }
    if (cnt)
        segs.push_back(cnt);
    m = segs.size();
    for (int i = 0; i < m; i++)
    {
        if (i == 0 && s[0] == '1')
        {
            times.push_back(segs[i]-1);
        }
        else if (i == m-1 && s[n-1] == '1')
        {
            times.push_back(segs[i]-1);
        }
        else if (segs[i] % 2 == 0)
        {
            times.push_back((segs[i]-2)/2);
        }
        else
        {
            times.push_back((segs[i]-1)/2);
        }
    }
    sort(times.begin(), times.end());
    ans = 0;
    cnt = 0;
    if (times.size() > 0)
        R = times[0];
    for (int j = 0; j < m; j++)
    {
        cnt = 0;
        if (segs[j] >= R+1)
        {
            segs[j] -= 1+R;
            cnt++;
        }
        while (segs[j] >= 2*R+2)
        {
            segs[j] -= 2*R+1;
            cnt++;
        }
        while (segs[j] > R)
        {
            segs[j] -= R+1;
            cnt++;
        }
        ans += cnt;
    }
    cout << ans;
}

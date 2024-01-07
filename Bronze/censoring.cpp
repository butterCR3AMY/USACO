// Censoring (bronze)
#include <iostream>
#include <string>
#include <vector>
#include <bitset>
using namespace std;
string s, cur, t;
vector<int> pre, nx;
int n, m, curPos = 0, curPos2;
int main()
{
    freopen("censor.in", "r", stdin);
    freopen("censor.out", "w", stdout);
    cin >> s >> t;
    m = t.length();
    n = s.length();
    for (int i= 0; i < n; i++)
    {
        pre.push_back(i-1);
        nx.push_back(i+1);
    }
    while(true)
    {
        if (curPos >= n)
            break;
        curPos2 = curPos;
        cur = "";
        for (int i = 0; i < m; i++)
        {
            if (curPos2 < n)
                cur += s[curPos2];
            else
                break;
            curPos2 = nx[curPos2];
        }
        if (cur == t)
        {
            if (pre[curPos] >= 0)
                nx[pre[curPos]] = curPos2;
            if (curPos2 < n)
                pre[curPos2] = pre[curPos];
            for (int i = 1; i < m; i++)
            {
                if (pre[curPos] >= 0)
                    curPos = pre[curPos];
                else
                    break;
            }
        }
        else
            curPos = nx[curPos];
    }
    curPos--;
    while(true)
    {
        if (pre[curPos] < 0)
            break;
        curPos = pre[curPos];
    }
    while(true)
    {
        if (curPos >= n || curPos < 0)
            break;
        cout << s[curPos];
        curPos = nx[curPos];
    }
}

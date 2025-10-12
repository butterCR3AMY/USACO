#include <iostream>
#include <map>
using namespace std;

long long n, nl, xg, yg, x, y, xi[40], yi[40], ans[41];
map<pair<long long, long long>, long long[41]> l;
void go(int i, int cur)
{
    if (i == nl)
    {
        l[{x,y}][cur]++;
        return;
    }
    x+=xi[i];
    y+=yi[i];
    go(i+1, cur+1);
    x-=xi[i];
    y-=yi[i];
    go(i+1, cur);
}
void go2(int i, int cur)
{
    if (i == nl-1)
    {
        for (int k = 0; k <= n-cur; k++)
        {
            if(!l.count({x, y}))
                break;
            ans[k+cur]+=l[{x,y}][k];
        }
        return;
    }
    x-=xi[i];
    y-=yi[i];
    go2(i-1, cur+1);
    x+=xi[i];
    y+=yi[i];
    go2(i-1, cur);
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    cin >> xg >> yg;
    for (int i = 0; i < n; i++)
        cin >> xi[i] >> yi[i];
    nl = n/2;
    //left is first nl instructions
    go(0, 0);
    x = xg;
    y = yg;
    go2(n-1, 0);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << '\n';
}

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct record{
    int day, change;
    string cow;
};
bool comp (record c1, record c2)
{
    return c1.day < c2.day;
}
int n, maxi, bessie, elsie, mildred, ans;
record cur[100];
bool b, e, m, newB, newE, newM;
int main()
{
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> cur[i].day >> cur[i].cow >> cur[i].change;
    sort(cur, cur+n, comp);
    b = true;
    e = true;
    m = true;
    for (int i = 0; i < n; i++)
    {
        if (cur[i].cow == "Mildred")
            mildred += cur[i].change;
        if (cur[i].cow == "Bessie")
            bessie += cur[i].change;
        if (cur[i].cow == "Elsie")
            elsie += cur[i].change;
        maxi = max(mildred, max(bessie, elsie));
        newB = false;
        newE = false;
        newM = false;
        if (mildred == maxi)
            newM = true;
        if (elsie == maxi)
            newE = true;
        if (bessie == maxi)
            newB = true;
        if (newE != e || newB != b || newM != m)
            ans++;
        e = newE;
        m = newM;
        b = newB;
    }
    cout << ans;
}

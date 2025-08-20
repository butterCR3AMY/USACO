#include <iostream>
using namespace std;

int n, b, mini, curBoot, start, last, nxt, dist, curStep, curDepth, a[300], d[300], s[300];
bool works;
int findNext(int pos)
{
    works = true;
    while (works)
    {
        works = false;
        for (int i = 1; i <= curStep; i++)
        {
            if (i+pos >= n)
                continue;
            if (a[i+pos] <= curDepth)
            {
                last = pos+i;
                works = true;
            }
        }
        pos = last;
    }
    return last;
}
int findLast(int depth, int last)
{
    int ans = 0;
    for (int i = 0; i <= last; i++)
        if (a[i] <= depth)
            ans = i;
    return ans;
}
int main()
{
    freopen("snowboots.in", "r", stdin);
    freopen("snowboots.out", "w", stdout);
    cin >> n >> b;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < b; i++)
        cin >> d[i] >> s[i];
    last = 0;
    nxt = 0;
    curDepth = d[0];
    curStep = s[0];
    dist = 0;
    curBoot = -1;
    while (last < n-1)
    {
        //cannot move any further with current boot
        curBoot++;
        curDepth = d[curBoot];
        curStep = s[curBoot];
        start = findLast(curDepth, last);
        nxt = findNext(start);
        last = nxt;
    }
    cout << curBoot;
}

#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

struct Point
{
    int num, tim;
};
bool comp (Point a, Point b)
{
    return a.tim<b.tim;
}
int n, i, j, maxi = 0, mini;
Point cows[100000];
int main()
{
    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);
    cin >> n;
    for (int i = 0; i <n; i++)
    {
        cin >> cows[i].num >> cows[i].tim;
    }
    sort(cows, cows+n, comp);
    i = 0;
    j = n-1;
    while (i <= j)
    {
        if (i == j)
        {
            maxi = max(maxi, cows[i].tim);
            i++;
            j--;
        }
        else
        {
            mini = min(cows[i].num, cows[j].num);
            cows[i].num -= mini;
            cows[j].num -= mini;
            maxi = max(maxi, cows[i].tim+cows[j].tim);
            if (cows[i].num == 0)
                i++;
            if (cows[j].num == 0)
                j--;
        }
    }
    cout << maxi;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long g, n, X, Y, T, curt, low, cnt, dist1, dist2;
struct event {
    long long x;
    long long y;
    long long t;
};
bool comp(event p1, event p2)
{
    return p1.t < p2.t;
}
event alibi[100000], grazing[100000];
vector<long long> times;
bool innocent;
int main()
{
    cin >> g >> n;
    for (int i = 0; i < g; i++)
    {
        cin >> X >> Y >> T;
        grazing[i].x = X;
        grazing[i].y = Y;
        grazing[i].t = T;
        times.push_back(T);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> X >> Y >> T;
        alibi[i].x = X;
        alibi[i].y = Y;
        alibi[i].t = T;
    }
    sort(grazing, grazing+g, comp);
    sort(alibi, alibi+n, comp);
    sort(times.begin(), times.end());
    for (int i = 0; i < n; i++)
    {
        //see if alibi is good
        innocent = false;
        curt = alibi[i].t;
        low = int(lower_bound(times.begin(), times.end(), curt)-times.begin());
        if (grazing[low].t == curt)
        {
            if (!(alibi[i].x == grazing[low].x && alibi[i].y == grazing[low].y))
                innocent = true;
        }
        else
        {
            //low-1 and low
            if (low != 0)
            {
                dist1 = abs(grazing[low-1].x-alibi[i].x)*abs(grazing[low-1].x-alibi[i].x)+abs(grazing[low-1].y-alibi[i].y)*abs(grazing[low-1].y-alibi[i].y);
                if (dist1 > abs(grazing[low-1].t-alibi[i].t)*abs(grazing[low-1].t-alibi[i].t))
                    innocent = true;
            }
            if (low != n)
            {
                dist2 = abs(grazing[low].x-alibi[i].x)*abs(grazing[low].x-alibi[i].x)+abs(grazing[low].y-alibi[i].y)*abs(grazing[low].y-alibi[i].y);
                if (dist2 > abs(grazing[low].t-alibi[i].t)*abs(grazing[low].t-alibi[i].t))
                    innocent = true;
            }
        }
        if (innocent)
            cnt++;
    }
    cout << cnt;
}

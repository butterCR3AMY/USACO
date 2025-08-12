#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define f first
#define s second
using namespace std;


bool comp (pair<int, int> p1, pair<int, int> p2)
{
    return p1.s < p2.s;
}
int n, x, y, ti, tj;
vector<pair<int, int>> norths, easts, cows;
bool stoppedn[1010], stoppede[1010];
char dir;
map<pair<int, int>, int> stops;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> dir >> x >> y;
        cows.push_back({x, y});
        if (dir == 'N')
            norths.push_back({x, y});
        else
            easts.push_back({x, y});
    }
    sort(norths.begin(), norths.end());
    sort(easts.begin(), easts.end(), comp);
    for (int i = 0; i < easts.size(); i++)
    {
        for (int j = 0; j < norths.size(); j++)
        {
            if (!stoppede[i] && !stoppedn[j] && easts[i].f < norths[j].f && easts[i].s > norths[j].s)
            {
                //possible they intersect
                ti = norths[j].f-easts[i].f;
                tj = easts[i].s-norths[j].s;
                if (ti < tj)
                {
                    //i reaches first and stops j
                    stops[easts[i]] += 1+stops[norths[j]];
                    stoppedn[j] = true;
                }
                else if (tj < ti)
                {
                    //j reaches first and stops i
                    stops[norths[j]] += 1+stops[easts[i]];
                    stoppede[i] = true;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << stops[cows[i]] << '\n';
}

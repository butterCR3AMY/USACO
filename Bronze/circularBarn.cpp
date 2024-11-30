#include <iostream>
#include <algorithm>
using namespace std;

int n, r[1000], cur, dist, mini = (int)1e9;
int main()
{
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> r[i];
    for (int door = 0; door < n; door++)
    {
        dist = 0;
        cur = door;
        for (int i = 1; i < n; i++)
        {
            cur = (cur+1)%n;
            dist += r[cur]*i;
        }
        mini = min(dist, mini);
    }
    cout << mini;
}

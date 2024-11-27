#include <iostream>
#include <algorithm>
#include <vector>
#define f first
#define s second
using namespace std;

pair<int, int> swaps[100];
int n, guess[100], maxi, pts, pos;
int main()
{
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> swaps[i].f >> swaps[i].s >> guess[i];
    for (int shell = 1; shell <= 3; shell++)
    {
        pts = 0;
        pos = shell;
        //do the swaps
        for (int i = 0; i < n; i++)
        {
            if (pos == swaps[i].f)
                pos = swaps[i].s;
            else if (pos == swaps[i].s)
                pos = swaps[i].f;
            if (guess[i] == pos)
                pts++;
        }
        maxi = max(pts, maxi);
    }
    cout << maxi;
}

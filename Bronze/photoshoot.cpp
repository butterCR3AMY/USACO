#include <iostream>
#include <fstream>
using namespace std;


int n, bPerm[1000], aPerm[1010], used[1010], cur;
bool allDiff = true;
int main()
{
    freopen("photo.in", "r", stdin);
    freopen("photo.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n-1; i++)
        cin >> bPerm[i];
    for (int starter = 1; starter <= n; starter++)
    {
        cur = starter;
        allDiff = true;
        for (int i = 0; i < n; i++)
        {
            used[i] = 0;
            aPerm[i] = 0;
        }
        aPerm[0] = cur;
        used[cur-1] ++;
        for (int i = 0; i < n-1; i++)
        {
            cur = bPerm[i]-cur;
            if (cur <= 0)
                break;
            aPerm[i+1] = cur;
            used[cur-1] ++;
        }
        if (cur <= 0)
            continue;
        for (int i = 0; i < n; i++)
            if (used[i] != 1)
                allDiff = false;
        if (allDiff)
        {
            for (int i = 0; i < n; i++)
            {
                if (i == n-1)
                    cout << aPerm[i];
                else
                    cout << aPerm[i] << " ";
            }
            break;
        }
    }
}

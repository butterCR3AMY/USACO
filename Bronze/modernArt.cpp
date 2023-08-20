#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int n, miniX[10], maxiX[10], miniY[10], maxiY[10], works[10], ans = 0;
string canvas[20];
int main()
{
    freopen("art.in", "r", stdin);
    freopen("art.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < 10; i++)
    {
        miniY[i] = 20;
        miniX[i] = 20;
        maxiY[i] = -1;
        maxiX[i] = -1;
        works[i] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> canvas[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i > maxiY[canvas[i][j]-'0'])
            {
                maxiY[canvas[i][j]-'0'] = i;
            }
            if (i < miniY[canvas[i][j]-'0'])
            {
                miniY[canvas[i][j]-'0'] = i;
            }
            if (j > maxiX[canvas[i][j]-'0'])
            {
                maxiX[canvas[i][j]-'0'] = j;
            }
            if (j < miniX[canvas[i][j]-'0'])
            {
                miniX[canvas[i][j]-'0'] = j;
            }
        }
    }
    for (int t = 1; t < 10; t++)
    {
        if (miniX[t] == 20)
        {
            works[t] = 0;
            continue;
        }
        for (int i = miniY[t]; i <= maxiY[t]; i++)
        {
            for (int j = miniX[t]; j <= maxiX[t]; j++)
            {
                if (canvas[i][j] != canvas[miniY[t]][miniX[t]])
                {
                    works[canvas[i][j]-'0'] = 0;
                }
            }
        }
    }
    for (int i = 1; i < 10; i++)
    {
        ans += works[i];
    }
    cout << ans;
}

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

#ifdef THIS
char dir[50];
int x[50], y[50];
int mins[50], n, mini = 1000000000, minCur = 1000000000, cur, marker[50];
vector <int> mPos;

int minIntersect(int i, int j)
{
    if ((x[i] > x[j] && y[i] > y[j] && dir[i] == 'S' && dir[j] == 'E')||(x[i] < x[j] && y[i] > y[j] && dir[i] == 'S' && dir[j] == 'W')||(x[i] > x[j] && y[i] < y[j] && dir[i] == 'N' && dir[j] == 'E')||(x[i] < x[j] && y[i] < y[j] && dir[i] == 'N' && dir[j] == 'W'))
    {
        if (abs(y[i]-y[j]) > abs(x[j]-x[i]) && ((mins[j] > abs(x[i]-x[j]) && marker[j] == -1)||marker[j] == 0))
            return abs(y[i]-y[j]);
        else
            return 1e9;
    }
    else if ((x[i] < x[j] && y[i] < y[j] && dir[i] == 'E' && dir[j] == 'S')||(x[i] < x[j] && y[i] > y[j] && dir[i] == 'E' && dir[j] == 'N')||((x[i] > x[j] && y[i] < y[j] && dir[i] == 'W' && dir[j] == 'S')||(x[i] > x[j] && y[i] > y[j] && dir[i] == 'W' && dir[j] == 'N')))
    {
        if (abs(x[i]-x[j]) > abs(y[j]-y[i]) && ((mins[j] > abs(y[i]-y[j]) && marker[j] == -1)||marker[j] == 0))
            return abs(x[i]-x[j]);
        else
            return 1e9;
    }
    else
        return 1e9;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> dir[i] >> x[i] >> y[i];
        marker[i] = 0;
    }
    for (int q = 0; q < n; q++)
    {
        mini = 1e9;
        for (int i = 0; i < n; i++)
        {
            minCur = 1e9;
            for (int j = 0; j < n; j++)
            {
                if (marker[i] == -1 || i == j)
                {
                    continue;
                }
                cur = minIntersect(i, j);
                if (cur < minCur)
                    minCur = cur;
            }
            if (minCur < mini)
            {
                mini = minCur;
                mPos.clear();
                mPos.push_back(i);
            }
            else if (minCur == mini)
                mPos.push_back(i);
        }
        if(mini != 1e9)
            for (int i : mPos)
            {
                marker[i] = -1;
                mins[i] = mini;
            }
    }
    for (int i = 0; i < n; i++)
    {
        if (mins[i] == 0 || mins[i] == 1e9)
            cout << "Infinity" << endl;
        else
            cout << mins[i] << endl;
    }
}
#endif

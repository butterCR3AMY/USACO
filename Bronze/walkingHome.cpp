//Walking Home
#include <iostream>
using namespace std;

int t, n, k, cnt, xD[4] = {-1, 0, 1, 0}, yD[4] = {0, 1, 0, -1};
string dirs = "URDL";
char arr[60][60];
void floodfill(int x, int y, int numTimes, char dir)
{
    char newDir = dir;
    int xx, yy, newNumTimes = numTimes;
    if (numTimes > k)
        return;
    if (numTimes == k && (dir == 'U' || dir == 'L' || (dir == 'R' && x != n-1) || (dir == 'D' && y != n-1)))
        return;
    if (x == n-1 && y == n-1)
    {
        if (numTimes <= k)
            cnt++;
        return;
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            xx = xD[i]+x;
            yy = yD[i]+y;
            newDir = dirs[i];
            newNumTimes = numTimes;
            if (xx < 0 || xx >= n || yy < 0 || yy >= n)
                continue;
            if (arr[xx][yy] == 'H')
                continue;
            if (newDir != dir && dir != '-')
                newNumTimes = numTimes+1;
            if (arr[xx][yy] == '.')
            {
                arr[xx][yy] = 'H';
                floodfill(xx, yy, newNumTimes, newDir);
                arr[xx][yy] = '.';
            }
        }
    }
}
int main()
{
    cin >> t;
    for (int q = 0; q < t; q++)
    {
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];
        }
        cnt = 0;
        arr[0][0] = 'H';
        floodfill(0, 0, 0, '-');
        cout << cnt << '\n';
    }
}

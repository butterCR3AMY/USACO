#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;

map<pii, int> pos;
char dir;
int n, curX = 0, curY = 0, dist, cnt = 1, maxi = 100010;
int main()
{
    freopen("mowing.in", "r", stdin);
    freopen("mowing.out", "w", stdout);
    cin >> n;
    pos[{0,0}] = 0;
    for (int q = 0; q < n; q++)
    {
        cin >> dir >> dist;
        if (dir == 'N')
        {
            for (int i = 0; i < dist; i++)
            {
                curY ++;
                if (pos.count({curX, curY}))
                {
                    if ((cnt-pos[{curX, curY}]) < maxi)
                        maxi = (cnt-pos[{curX, curY}]);
                }
                pos[{curX, curY}] = cnt;
                cnt ++;
            }
        }
        else if (dir == 'E')
        {
            for (int i = 0; i < dist; i++)
            {
                curX ++;
                if (pos.count({curX, curY}))
                {
                    if ((cnt-pos[{curX, curY}]) < maxi)
                        maxi = (cnt-pos[{curX, curY}]);
                }
                pos[{curX, curY}] = cnt;
                cnt ++;
            }
        }
        else if (dir == 'S')
        {
            for (int i = 0; i < dist; i++)
            {
                curY --;
                if (pos.count({curX, curY}))
                {
                    if ((cnt-pos[{curX, curY}]) < maxi)
                        maxi = (cnt-pos[{curX, curY}]);
                }
                pos[{curX, curY}] = cnt;
                cnt ++;
            }
        }
        else if (dir == 'W')
        {
            for (int i = 0; i < dist; i++)
            {
                curX --;
                if (pos.count({curX, curY}))
                {
                    if ((cnt-pos[{curX, curY}]) < maxi)
                        maxi = (cnt-pos[{curX, curY}]);
                }
                pos[{curX, curY}] = cnt;
                cnt ++;
            }
        }
    }
    if (maxi == 100010)
        cout << -1;
    else
        cout << maxi << endl;
}

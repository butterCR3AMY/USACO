#include <iostream>
using namespace std;

int ans, x1, y1, x2, y2, x3, y3, x4, y4, x1t, y1t, x2t, y2t, mat[2001][2001];
int main()
{
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4 >> x1t >> y1t >> x2t >> y2t;
    //set billboard1 to 1's
    for (int i = x1+1000; i < x2+1000; i++)
        for (int j = y1+1000; j < y2+1000; j++)
            mat[i][j] = 1;
    //set billboard2 to 1's
    for (int i = x3+1000; i < x4+1000; i++)
        for (int j = y3+1000; j < y4+1000; j++)
            mat[i][j] = 1;
    //set truck to 0's
    for (int i = x1t+1000; i < x2t+1000; i++)
        for (int j = y1t+1000; j < y2t+1000; j++)
            mat[i][j] = 0;
    for (int i = 0; i < 2001; i++)
    {
        for (int j = 0; j < 2001; j++)
            ans += mat[i][j];
    }
    cout << ans;
}

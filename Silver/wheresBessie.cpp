#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define f first
#define s second
using namespace std;

int n, alph[26], visited[20][20], num, dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};
string cow[20];
char color1, color2, reg1, reg2;
bool works;
vector<pair<pair<int, int>, pair<int, int>>> res;
void reset()
{
    for (int i = 0; i < 26; i++)
        alph[i] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            visited[i][j] = 0;
    }
    reg1 = 0;
    reg2 = 0;
    num = 0;
}
void go(int x, int y, int l, int r, int d, int u)
{
    int x2, y2;
    visited[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        x2 = x+dx[i];
        y2 = y+dy[i];
        if (x2 >= l && y2 >= d && x2 <= r && y2 <= u && !visited[x2][y2] && cow[x2][y2] == cow[x][y])
            go(x2, y2, l, r, d, u);
    }
}
int findNumR (char color, int l, int r, int d, int u)
{
    int cnt = 0;
    for (int i = l; i <= r; i++)
    {
        for (int j = d; j <= u; j++)
        {
            if (visited[i][j])
                continue;
            if (cow[i][j] == color)
            {
                cnt++;
                go(i, j, l, r, d, u);
            }
        }
    }
    return cnt;
}
int main()
{
    freopen("where.in", "r", stdin);
    freopen("where.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> cow[i];
    for (int l = 0; l < n;  l++)
    {
        for (int r = n-1; r >= 0; r--)
        {
            for (int d = 0; d < n; d++)
            {
                for (int u = n-1; u >= 0; u--)
                {
                    if (l > r || d > u)
                        continue;
                    reset();
                    for (int i = l; i <= r; i++)
                    {
                        for (int j = d; j <= u; j++)
                            alph[cow[i][j]-'A']++;
                    }
                    for (int i = 0; i < 26; i++)
                    {
                        if (alph[i])
                        {
                            num++;
                            if (num == 1)
                                color1 = (char)(i+'A');
                            if (num == 2)
                                color2 = (char)(i+'A');
                        }
                    }
                    if (num != 2)
                        continue;
                    //find num regions of color1
                    reg1 = findNumR(color1, l, r, d, u);
                    //find num regions of color2
                    reg2 = findNumR(color2, l, r, d, u);
                    if ((reg1 == 1 && reg2 >= 2) || (reg2 == 1 && reg1 >= 2))
                    {
                        //check if not in other PCL
                        works = true;
                        for (int i = 0; i < res.size(); i++)
                        {
                            if (res[i].f.f <= l && res[i].f.s >= r && res[i].s.f <= d && res[i].s.s >= u)
                                works = false;
                        }
                        if (works)
                            res.push_back({{l, r}, {d, u}});
                    }
                }
            }
        }
    }
    cout << res.size();
}

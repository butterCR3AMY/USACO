#include <iostream>
using namespace std;

int n, c, cur, ans, num1[100010], num2[100010], pos[512], m, maxInd;
int has[512][512], maxi[512][512], exist[512], cur1, cur2;
string barn[100010];
int main()
{
    cin >> c >> n;
    for (int i = 0; i < n; i++)
        cin >> barn[i];
    for (int i = 0; i < 512; i++)
        pos[i] = -1;
    if (c > 9)
    {
        //do the split into 2 strat
        for (int i = 0; i < n; i++)
        {
            cur1 = 0;
            for (int j = 0; j < 9; j++)
            {
                cur1 *= 2;
                if (barn[i][j] == 'G') //1
                    cur1++;
            }
            cur2 = 0;
            for (int j = 9; j < c; j++)
            {
                cur2 *= 2;
                if (barn[i][j] == 'G') //1
                    cur2++;
            }
            exist[cur1] = 1;
            has[cur1][cur2] = 1;
            num1[i] = cur1;
            num2[i] = cur2;
        }
        for (int sec = 0; sec < 512; sec++)
        {
            //if you have a barn where second = sec
            for (int i = 0; i < 512; i++)
            {
                for (int j = 0; j < 512; j++)
                {
                    if (has[i][j] == 0)
                        continue;
                    maxi[i][sec] = max(maxi[i][sec], __builtin_popcount(j^sec));
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            ans = 0;
            for (int j = 0; j < 512; j++)
            {
                if (exist[j] == 0)
                    continue;
                ans = max(ans, maxi[j][num2[i]]+__builtin_popcount(num1[i]^j));
            }
            cout << ans << '\n';
        }
    }
    else
    {
        //do w/o split
        for (int i = 0; i < n; i++)
        {
            cur = 0;
            for (int j = 0; j < c; j++)
            {
                cur *= 2;
                if (barn[i][j] == 'G') //1
                    cur++;
                else //2
                    cur+=0;
            }
            num1[i] = cur;
            pos[cur] = i;
        }
        for (int i = 0; i < n; i++)
        {
            m = -1;
            for (int j = 0; j < 512; j++)
            {
                if (pos[j] == -1)
                    continue;
                m = max(m, __builtin_popcount(num1[i]^j));
            }
            cout << m << '\n';
        }
    }
}

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool possible = true, drank = false;
map<int, int> sickTime;
int n, m, d, s, milks[1010][3], curPerson, curTime, maxi, cur, cnt = 0;
int main()
{
    freopen("badmilk.in", "r", stdin);
    freopen("badmilk.out", "w", stdout);
    cin >> n >> m >> d >> s;
    for (int i = 0; i < d; i++)
    {
        cin >> milks[i][0] >> milks[i][1] >> milks[i][2];
    }
    for (int i = 0; i < s; i++)
    {
        cin >> curPerson >> curTime;
        sickTime[curPerson] = curTime;
    }
    for (int badMilk = 1; badMilk <= m; badMilk++)
    {
        possible = true;
        cnt = 0;
        for (int person = 1; person <= n; person++)
        {
            if (!(sickTime.count(person)))
                continue;
            drank = false;
            for (int i = 0; i < d; i++)
            {
                if (milks[i][0] == person)
                {
                    if (milks[i][1] == badMilk)
                    {
                        drank = true;
                        if (sickTime[person] > milks[i][2])
                        {
                            break;
                        }
                        else if (sickTime[person] <= milks[i][2])
                        {
                            possible = false;
                        }
                    }
                }
            }
            if (drank == false)
                possible = false;
        }
        if (possible)
        {
            for (int person = 1; person <= n; person++)
            {
                for (int i = 0; i < d; i++)
                {
                    if (milks[i][0] == person && milks[i][1] == badMilk)
                    {
                        cnt ++;
                        break;
                    }
                }
            }
            if (cnt > maxi)
                maxi = cnt;
        }
    }
    cout << max(maxi, s) << endl;
}

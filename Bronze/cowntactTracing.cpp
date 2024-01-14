//cowntact tracing
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct HS
{
    int tim, rec;
};
bool comp (HS a, HS b)
{
    return a.tim < b.tim;
}
bool works;
string sick, simU;
HS cur;
int n, m, T, t, x, y, curS, minK, maxK, sim[250], num = 0, cnt, curShakes[250], infected[250], startT;
vector<vector<HS>> shake;
int main()
{
    freopen("tracing.in", "r", stdin);
    freopen("tracing.out", "w", stdout);
    cin >> n >> T;
    cin >> sick;
    shake.resize(n);
    for (int i = 0; i < T; i++)
    {
        cin >> t >> x >> y;
        x--;
        y--;
        cur.tim = t;
        cur.rec = y;
        shake[x].push_back(cur);
        cur.rec = x;
        shake[y].push_back(cur);
    }
    for (int i = 0; i < n; i++)
        sort(shake[i].begin(), shake[i].end(), comp);
    minK = T;
    maxK = 0;
    for (int zero = 0; zero < n; zero++)
    {
        works = false;
        for (int i = 0; i < n; i++)
        {
            sim[i] = 0;
            curShakes[i] = 0;
            infected[i] = -1;
        }
        sim[zero] = 1;
        infected[zero] = -2;
        for (int k = 0; k <= T; k++)
        {
            // loop through all pos in time
            for (int curTim = 0; curTim <= 250; curTim++)
            {
                for (int i = 0; i < n; i++)
                {
                    if (sim[i] == 0 || curShakes[i] == k)
                        continue;
                    m = int(shake[i].size());
                    for (int j = 0; j < m; j++)
                    {
                        if (shake[i][j].tim == curTim && shake[i][j].tim != infected[i])
                        {
                            sim[shake[i][j].rec] = 1;
                            if (infected[shake[i][j].rec] == -1)
                                infected[shake[i][j].rec] = curTim;
                            curShakes[i]++;
                        }
                    }
                }
            }
            simU = "";
            for (int i = 0; i < n; i++)
            {
                if (sim[i] == 1)
                    simU += "1";
                else
                    simU += "0";
            }
            if (simU == sick)
            {
                minK = min(minK, k);
                maxK = max(maxK, k);
                works = true;
            }
            for (int i = 0; i < n; i++)
            {
                sim[i] = 0;
                curShakes[i] = 0;
                infected[i] = -1;
            }
            sim[zero] = 1;
            infected[zero] = -2;
        }
        if (works)
        {
            num++;
        }
    }
    cout << num << " " << minK << " ";
    if (maxK == T)
        cout << "Infinity";
    else
        cout << maxK;
}

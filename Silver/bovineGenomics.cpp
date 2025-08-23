#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int n, m, ans;
string plain[510], spotty[510], cur;
set<string> combos;
bool works;
int main()
{
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> spotty[i];
    for (int i = 0; i < n; i++)
        cin >> plain[i];
    for (int a = 0; a < m-2; a++)
    {
        for (int b = a+1; b < m-1; b++)
        {
            for (int c = b+1; c < m; c++)
            {
                //3 positions are a b and c
                combos.clear();
                for (int i = 0; i < n; i++)
                {
                    cur = "";
                    cur += spotty[i][a];
                    cur += spotty[i][b];
                    cur += spotty[i][c];
                    combos.insert(cur);
                }
                works = true;
                for (int i = 0; i < n; i++)
                {
                    cur = "";
                    cur += plain[i][a];
                    cur += plain[i][b];
                    cur += plain[i][c];
                    if (combos.find(cur) != combos.end())
                    {
                        works = false;
                        break;
                    }
                }
                if(works)
                    ans++;
            }
        }
    }
    cout << ans;
}

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int n, k;
string cur;
bool iThere = false, jThere = false, iHere = false, jHere = false;
vector<string> cow[30];
int main()
{
    freopen("evolution.in", "r", stdin);
    freopen("evolution.out", "w", stdout);
    cin >> n;
    for (int q = 0; q < n; q++)
    {
        cow[q].clear();
        cin >> k;
        for (int i = 0; i < k; i++)
        {
            cin >> cur;
            cow[q].push_back(cur);
        }
    }
    for (int q = 0; q < n; q++)
    {
        for (int i = 0; i < cow[q].size(); i++)
        {
            for (int j = 0; j < cow[q].size(); j++)
            {
                if (i == j)
                    continue;
                iThere = false;
                jThere = false;
                for (int r = 0; r < n; r++)
                {
                    if (r == q)
                        continue;
                    iHere = false;
                    jHere = false;
                    for (int k = 0; k < cow[r].size(); k++)
                    {
                        if (cow[r][k] == cow[q][i])
                            iHere = true;
                        if (cow[r][k] == cow[q][j])
                            jHere = true;
                    }
                    if (iHere && !jHere)
                        iThere = true;
                    if (jHere && !iHere)
                        jThere = true;
                }
                if (iThere && jThere)
                {
                    cout << "no" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "yes" << endl;
}

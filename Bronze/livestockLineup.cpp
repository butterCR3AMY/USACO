#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
using namespace std;

int n;
bool works = false, overall = true;
string needs[7][2], noNeed;
vector<string> cows;
int main()
{
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);
    cows.push_back("Beatrice");
    cows.push_back("Belinda");
    cows.push_back("Bella");
    cows.push_back("Bessie");
    cows.push_back("Betsy");
    cows.push_back("Blue");
    cows.push_back("Buttercup");
    cows.push_back("Sue");
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> needs[i][0];
        for (int j = 0; j < 4; j++)
            cin >> noNeed;
        cin >> needs[i][1];
    }
    while (next_permutation(cows.begin(), cows.end()))
    {
        overall = true;
        for (int j = 0; j < n; j++)
        {
            works = false;
            for (int i = 1; i < 8; i++)
            {
                if ((cows[i] == needs[j][0] && cows[i-1] == needs[j][1]) || (cows[i-1] == needs[j][0] && cows[i] == needs[j][1]))
                {
                    works = true;
                    break;
                }
            }
            if (!works)
            {
                overall = false;
            }
        }
        if (overall)
            break;
    }
    for (int i = 0; i < 8; i++)
        cout << cows[i] << endl;
}

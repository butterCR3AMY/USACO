#include <iostream>
#include <vector>
using namespace std;

int n, is[100010], want[100010], dif[100010], commands = 0, mini;
vector<int> needChange, newNeedChange;
void changeTemp()
{
    for (int q = 0; q < 2; q++)
    {
        newNeedChange.clear();
        for (int i = 0; i < n; i++)
        {
            if (dif[i] > 0)
                newNeedChange.push_back(i);
        }
        if (newNeedChange.size() > 0)
        {
            int pre = 0;
            mini = dif[newNeedChange[0]];
            for (int i = 1; i < newNeedChange.size(); i++)
            {
                if (newNeedChange[i] != newNeedChange[i-1]+1)
                {
                    for(int j = pre; j < i; j ++)
                        dif[newNeedChange[j]] -= mini;
                    commands += mini;
                    mini = 10000;
                    pre = i;
                }
                mini = min(mini, dif[newNeedChange[i]]);
            }
            for(int j = pre; j < newNeedChange.size(); j ++)
                dif[newNeedChange[j]] -= mini;
            commands += mini;
        }
        for (int i = 0; i < n; i++)
        {
            dif[i] = 0-dif[i];
        }
    }
    for (int i = 0; i < n; i++)
        if (dif[i] != 0)
            return changeTemp();
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> want[i];
    for (int i = 0; i < n; i++)
        cin >> is[i];
    for (int i = 0; i < n; i++)
        dif[i] = want[i]-is[i];
    changeTemp();
    cout << commands;
}

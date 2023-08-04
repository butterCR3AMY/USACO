#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int n, k, a1, a2, b1, b2, other, start, last, pos;
vector<int> cows;
bool cycle = false;
vector<vector<int>> cycles;
set<vector<int>> dif;
int main()
{
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);
    cin >> n >> k >> a1 >> a2 >> b1 >> b2;
    a1 --;
    a2 --;
    b1 --;
    b2 --;
    for (int i = 0; i < n; i++)
        cows.push_back(i+1);
    cycles.push_back(cows);
    while (true)
    {
        for (int i = a1; i <= (a1+a2)/2; i++)
            swap(cows[i], cows[a2-i+a1]);
        for (int i = b1; i <= (b1+b2)/2; i++)
            swap(cows[i], cows[b2-i+b1]);
        cycles.push_back(cows);
        if (dif.count(cows) > 0)
        {
            for (int i = 0; i < cycles.size()-1; i++)
            {
                if (cycles[i] == cycles[cycles.size()-1])
                {
                    start = i;
                    last = cycles.size()-2;
                    cycle = true;
                    break;
                }
            }
        }
        dif.insert(cows);
        if (cycle == true || cycles.size()-1 == k)
            break;
    }
    if (cycle == true)
    {
        pos = ((k-start)%(last-start+1)+start);
    }
    else
    {
        pos = cycles.size()-1;
    }
    for (int i = 0; i < n; i++)
        cout << cycles[pos][i] << endl;
}

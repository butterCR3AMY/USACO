#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int n, m;
long long cur, base, eaten;
vector<long long> cow, cane;
string s;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> cur;
        cow.push_back(cur);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> cur;
        cane.push_back(cur);
    }
    for (int i = 0; i < m; i++)
    {
        cur = cane[i];
        base = 0;
        for (int j = 0; j < n; j++)
        {
            if (cow[j] >= base)
            {
                eaten = min(cow[j]-base, cane[i]-base);
                base = min(cow[j], cane[i]);
                cow[j] += eaten;
            }
            if (base >= cur)
                break;
        }
    }
    for (int i = 0; i < n; i++)
        cout << cow[i] << '\n';
}

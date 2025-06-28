#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, x, y, maxi;
vector<int> nxt[100001];
int main()
{
    freopen("planting.in", "r", stdin);
    freopen("planting.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n-1; i++)
    {
        cin >> x >> y;
        nxt[x].push_back(y);
        nxt[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        maxi = max(int(nxt[i].size()+1), maxi);
    }
    cout << maxi;
}

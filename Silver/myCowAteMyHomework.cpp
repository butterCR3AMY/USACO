#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long hw[100000], n, cur, score[100000], m, mN = 1, mini = 10000;
vector<long long> maxi;
int main()
{
    freopen("homework.in", "r", stdin);
    freopen("homework.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> hw[i];
    for (int i = n-1; i > 0; i--)
    {
        cur += hw[i];
        mini = min(mini, hw[i]);
        score[i] = cur-mini;
        if (score[i]*mN > m*(n-i-1))
        {
            m = score[i];
            mN = n-i-1;
            maxi.clear();
            maxi.push_back(i);
        }
        else if (score[i]*mN == m*(n-i-1))
            maxi.push_back(i);
    }
    sort(maxi.begin(), maxi.end());
    for (int i = 0; i < maxi.size(); i++)
        cout << maxi[i] << '\n';
}

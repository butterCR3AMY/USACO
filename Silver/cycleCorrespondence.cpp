#include <iostream>
#include <algorithm>
#include <vector>
#define f first
#define s second
using namespace std;

int n, k, maxi1, a[500010], b[500010], pos[500010], pos2[500010], cnt, cnt2, cnt3;
vector<int> diff, diff2;
int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        pos[i] = -1;
        pos2[i] = -1;
    }
    for (int i = 0; i < k; i++)
    {
        cin >> a[i];
        pos[a[i]-1] = i;
    }
    for (int i = 0; i < k; i++)
    {
        cin >> b[i];
        pos2[b[i]-1] = i;
    }
    for (int i = 0; i < n; i++)
        if (pos[i] == -1 && pos2[i] == -1)
            cnt3++;
    for (int i = 0; i < n; i++)
    {
        if (pos[i] == -1 || pos2[i] == -1)
        {
            diff.push_back(-1000000);
            diff.push_back(-1000000);
            continue;
        }
        diff.push_back(pos2[i]-pos[i]);
        if (pos2[i] < pos[i])
            diff.push_back(pos2[i]-pos[i]+k);
        else
            diff.push_back(pos2[i]-pos[i]-k);
    }
    sort(diff.begin(), diff.end());
    for (int i = 0; i < n; i++)
    {
        if (pos[i] == -1 || pos2[i] == -1)
        {
            diff2.push_back(-1000000);
            diff2.push_back(-1000000);
            continue;
        }
        diff2.push_back(k-1-pos2[i]-pos[i]);
        if (k-1-pos2[i] < pos[i])
            diff2.push_back(k-1-pos2[i]-pos[i]+k);
        else
            diff2.push_back(k-1-pos2[i]-pos[i]-k);
    }
    sort(diff2.begin(), diff2.end());
    for (int i = 0; i < 2*n; i++)
    {
        if (diff[i] == -1000000)
            continue;
        if (i == 0)
            cnt++;
        else if (diff[i-1] == diff[i])
            cnt++;
        else
        {
            maxi1 = max(maxi1, cnt);
            cnt = 1;
        }
    }
    maxi1 = max(maxi1, cnt);
    for (int i = 0; i < 2*n; i++)
    {
        if (diff2[i] == -1000000)
            continue;
        if (i == 0)
            cnt2++;
        else if (diff2[i-1] == diff2[i])
            cnt2++;
        else
        {
            maxi1 = max(maxi1, cnt2);
            cnt2 = 1;
        }
    }
    maxi1 = max(maxi1, cnt2);
    cout << maxi1+cnt3 << '\n';
}

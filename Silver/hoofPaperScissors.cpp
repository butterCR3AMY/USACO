#include <iostream>
using namespace std;

int n, h[100000], p[100000], s[100000], bfor, aftr, ans;
int hB, pB, sB, hA, pA, sAf;
char cur;
int main()
{
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> cur;
        if (i > 0)
        {
            h[i] = h[i-1];
            p[i] = p[i-1];
            s[i] = s[i-1];
        }
        if (cur == 'H')
            h[i]++;
        if (cur == 'P')
            p[i]++;
        if (cur == 'S')
            s[i]++;
    }
    for (int sw = 0; sw <= n; sw++)
    {
        if (sw == 0)
            ans = max(ans, max(h[n-1], max(p[n-1], s[n-1])));
        else if (sw == n)
            ans = max(ans, max(h[n-1], max(p[n-1], s[n-1])));
        else
        {
            hA = h[n-1]-h[sw-1];
            pA = p[n-1]-p[sw-1];
            sAf = s[n-1]-s[sw-1];
            aftr = max(hA, max(pA, sAf));
            hB = h[sw-1];
            pB = p[sw-1];
            sB = s[sw-1];
            bfor = max(hB, max(pB, sB));
            ans = max(ans, bfor+aftr);
        }
    }
    cout << ans;
}

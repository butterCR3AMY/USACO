#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int c[3], m[3], cur, nxt;
int main()
{
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);
    for (int i = 0; i < 3; i++)
        cin >> c[i] >> m[i];
    for (int t = 0; t < 100; t++)
    {
        //poor from cur to nxt
        nxt = (cur+1)%3;
        if (m[cur]+m[nxt] <= c[nxt])
        {
            m[nxt] += m[cur];
            m[cur] = 0;
        }
        else
        {
            m[cur] -= c[nxt]-m[nxt];
            m[nxt] = c[nxt];
        }
        cur = nxt;
    }
    cout << m[0] << '\n'<< m[1] << '\n' << m[2];
}

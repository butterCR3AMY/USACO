#include <iostream>
using namespace std;

int q, n, c, o, w, a, b, prefC[200010], prefO[200010], prefW[200010];
string s;
int main()
{
    cin >> s;
    cin >> q;
    n = (int)s.length();
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
        {
            prefC[i] = prefC[i-1];
            prefO[i] = prefO[i-1];
            prefW[i] = prefW[i-1];
        }
        if (s[i] == 'C')
            prefC[i]++;
        if (s[i] == 'O')
            prefO[i]++;
        if (s[i] == 'W')
            prefW[i]++;
    }
    while(q--)
    {
        cin >> a >> b;
        a--;
        b--;
        c = prefC[b];
        o = prefO[b];
        w = prefW[b];
        if (a != 0)
        {
            c -= prefC[a-1];
            o -= prefO[a-1];
            w -= prefW[a-1];
        }
        if (c%2 == 0)
        {
            if (o%2 == 1 && w%2 == 1)
                cout << 'Y';
            else
                cout << 'N';
        }
        else
        {
            if (o%2 == 0 && w%2 == 0)
                cout << 'Y';
            else
                cout << 'N';
        }
    }
}

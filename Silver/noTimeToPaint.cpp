#include <iostream>
using namespace std;

int n, q, a, b, after, bfor, cnt, l[27][100010], r[27][100010];
string s;
bool separate;
char c;
int main()
{
    cin >> n >> q;
    cin >> s;
    for (int cur = 0; cur < 26; cur++)
    {
        c = (char)(cur+'A');
        cnt = 0;
        //look at brushstrokes for cur color
        separate = true;
        for (int i = 0; i < n; i++)
        {
            if (i > 0)
                l[cur][i] = l[cur][i-1];
            else
                l[cur][i] = 0;
            if (separate && c == s[i])
            {
                separate = false;
                l[cur][i]++;
            }
            if (s[i] < c)
                separate = true;
        }
    }
    for (int cur = 0; cur < 26; cur++)
    {
        c = (char)(cur+'A');
        cnt = 0;
        //look at brushstrokes for cur color
        separate = true;
        for (int i = n-1; i >= 0; i--)
        {
            if (i < n-1)
                r[cur][i] = r[cur][i+1];
            else
                r[cur][i] = 0;
            if (separate && c == s[i])
            {
                separate = false;
                r[cur][i]++;
            }
            if (s[i] < c)
                separate = true;
        }
    }
    while(q--)
    {
        cin >> a >> b;
        a -= 2;
        bfor = 0;
        after = 0;
        if (a >= 0)
            for (int i = 0; i < 26; i++)
                bfor += l[i][a];
        if (b < n)
            for (int i = 0; i < 26; i++)
                after += r[i][b];
        cout << bfor+after << '\n';
    }
}

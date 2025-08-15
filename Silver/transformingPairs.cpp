#include <iostream>
using namespace std;

long long t, a, b, c, d, ans, nxt;
bool works;
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> c >> d;
        ans = 0;
        works = false;
        if (c == a && d == b)
        {
            cout << 0 << '\n';
            continue;
        }
        while (c >= a && d >= b)
        {
            if (c == a && d == b)
            {
                works = true;
                break;
            }
            if (c == a && (d-b)%c == 0)
            {
                ans += (d-b)/c;
                works = true;
                break;
            }
            if (c == a && (d-b)%c != 0)
                break;
            if (d == b && (c-a)%d == 0)
            {
                ans += (c-a)/d;
                works = true;
                break;
            }
            if (d == b && (c-a)%d != 0)
                break;
            if (c > d)
            {
                if (d > a)
                {
                    ans += c/d;
                    c = c%d;
                }
                else
                {
                    if ((c-a)%d == 0)
                    {
                        ans += (c-a)/d;
                        c = a;
                    }
                    else
                        break;
                }
            }
            else if (d > c)
            {
                if (c > b)
                {
                    ans += d/c;
                    d = d%c;
                }
                else
                {
                    if ((d-b)%c == 0)
                    {
                        ans += (d-b)/c;
                        d = b;
                    }
                    else
                        break;
                }
            }
            else
                break;
        }
        if (works)
            cout << ans << '\n';
        else
            cout << -1 << '\n';
    }
}

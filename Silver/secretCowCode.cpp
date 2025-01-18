#include <iostream>
using namespace std;

long long ans, n, len;
string s;
void go(long long n)
{
    if (n <= s.length())
    {
        ans = n;
        return;
    }
    len/=2;
    if (n <= len)
        go(n);
    else
    {
        if (n == len+1)
            go(len);
        else
            go(n-len-1);
    }
}
int main()
{
    freopen("cowcode.in", "r", stdin);
    freopen("cowcode.out", "w", stdout);
    cin >> s >> n;
    len = s.length();
    while (len < n)
        len *= 2;
    go(n);
    cout << s[ans-1];
}

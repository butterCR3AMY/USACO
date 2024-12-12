#include <iostream>
using namespace std;

int n, m, a[20], b[20], req[101], cur[101], mark[20], temp[20], money[20], s[20], t[20], c[20], mini = 10000, curM;
bool works;
void gen(int i)
{
    if (i == m)
    {
        //try out combo of AC's
        for (int j = 0; j <= 100; j++)
            cur[j] = 0;
        curM = 0;
        for (int j = 0; j < m; j++)
        {
            if (mark[j] == 0)
                continue;
            curM += money[j];
            for (int k = a[j]; k <= b[j]; k++)
                cur[k] += temp[j];
        }
        works = true;
        //see if good;
        for (int j = 0; j < 101; j++)
        {
            if (req[j] > cur[j])
                works = false;
        }
        if (works)
            mini = min(curM, mini);
        return;
    }
    mark[i] = 1;
    gen(i+1);
    mark[i] = 0;
    gen(i+1);
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> s[i] >> t[i] >> c[i];
    for (int i = 0; i < m; i++)
        cin >> a[i] >> b[i] >> temp[i] >> money[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = s[i]; j <= t[i]; j++)
            req[j] += c[i];
    }
    gen(0);
    cout << mini;
}

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int n, range[110][2], start = 100, before1 = 0, before2 = 1000000, after1 = 0, after2 = 1000000, last = 0;
string type[110];
int main()
{
    freopen("traffic.in", "r", stdin);
    freopen("traffic.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> type[i];
        cin >> range[i][0] >> range[i][1];
    }
    for (int i = 0; i < n; i++)
    {
        if (type[i] == "none")
        {
            start = i;
            break;
        }
    }
    for (int i = start; i < n; i++)
    {
        if (type[i] == "none")
        {
            last = i;
            before1 = range[i][0];
            before2 = range[i][1];
        }
    }
    for (int i = last; i >= 0; i--)
    {
        if (type[i] == "none")
        {
            before1 = max(range[i][0], before1);
            before2 = min(range[i][1], before2);
        }
        else if (type[i] == "on")
        {
            before1 -= range[i][1];
            before2 -= range[i][0];
        }
        else if (type[i] == "off")
        {
            before1 += range[i][0];
            before2 += range[i][1];
        }
    }
    after1 = before1;
    after2 = before2;
    for (int i = 0; i < n; i++)
    {
        if (type[i] == "none")
        {
            after1 = max(range[i][0], after1);
            after2 = min(range[i][1], after2);
        }
        else if (type[i] == "on")
        {
            after1 += range[i][0];
            after2 += range[i][1];
        }
        else if (type[i] == "off")
        {
            after1 -= range[i][1];
            after2 -= range[i][0];
        }
    }
    cout << max(min(before1, before2), 0) << " " << max(max(before2, before1), 0) << endl;
    cout << max(min(after1, after2), 0) << " " << max(max(after2, after1), 0) << endl;
}

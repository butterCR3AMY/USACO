#include <iostream>
using namespace std;

int n, a[100010], dir, pos, total, cnt;
int changeDir(int d)
{
    if (pos == n && d == 1)
        return 0;
    else if (pos == 0 && d == 0)
        return 1;
    else if (d == 1 && pos > 0 && a[pos] == 1 && a[pos-1] != 0)
        return 0;
    else if (d == 0 && pos != 0 && a[pos-1] == 1 && a[pos] != 0)
        return 1;
    else if (d == 1 && a[pos] == 0)
        return 0;
    else if (d == 0 && pos > 0 && a[pos-1] == 0)
        return 1;
    return d;
}
void go()
{
    dir = changeDir(dir);
    if (cnt == total)
        return;
    if (dir == 1)
    {
        a[pos]--;
        pos++;
        cnt++;
        cout << 'R';
    }
    else
    {
        pos--;
        a[pos]--;
        cnt++;
        cout << 'L';
    }
    go();
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        total += a[i];
    }
    //simulate
    //1 means right 0 means left
    dir = 1;
    pos = 0;
    go();
}

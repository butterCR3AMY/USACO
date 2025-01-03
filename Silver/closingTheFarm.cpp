#include <iostream>
#include <vector>
using namespace std;

int n, m, q, cur1, cur2, mark[3000], cur[3000], curr;
vector<int> reach[3000];
bool connected;
void go(int x)
{
    cur[x] = 1;
    for (int i = 0; i < reach[x].size(); i++)
    {
        if (!cur[reach[x][i]] && mark[reach[x][i]])
            go(reach[x][i]);
    }
}
int main()
{
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> cur1 >> cur2;
        reach[cur1-1].push_back(cur2-1);
        reach[cur2-1].push_back(cur1-1);
    }
    for (int i = 0; i < n; i++)
    {
        mark[i] = 1;
        cur[i] = 0;
    }
    //see if whole farm connected
    go(0);
    connected = true;
    for (int i = 0; i < n; i++)
    {
        if (mark[i] != cur[i])
            connected = false;
    }
    if (connected)
        cout << "YES\n";
    else
        cout << "NO\n";
    for (int t = 0; t < n-1; t++)
    {
        cin >> q;
        q--;
        mark[q] = 0;
        for (int i = 0; i < n; i++)
            cur[i] = 0;
        //see if connected
        for (int i = 0; i < n; i++)
        {
            if (mark[i])
            {
                curr = i;
                break;
            }
        }
        go(curr);
        connected = true;
        for (int i = 0; i < n; i++)
        {
            if (mark[i] != cur[i])
                connected = false;
        }
        if (connected)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}

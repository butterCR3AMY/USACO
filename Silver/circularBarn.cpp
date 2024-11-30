#include <iostream>
#include <vector>
#include <queue>
#include <bitset>
#include <cstring>
using namespace std;

int n, c[1000], cog[1000], mini = (int)1e9, dist;
vector<int> pos;
queue<int> q;
bitset<1000> mark;
int main()
{
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
        if (!c[i])
            pos.push_back(i);
    }
    memcpy(cog, c, sizeof(c));
    for (int start = 0; start < n; start++)
    {
        while (!q.empty())
            q.pop();
        dist = 0;
        mark.reset();
        for (int i = 0; i < 2*n; i++)
        {
            if (!mark[(start+i)%n])
            {
                for (int j = 0; j < (c[(start+i)%n]); j++)
                    q.push(i);
                c[(start+i)%n] = 0;
                if(!q.empty())
                {
                    dist += (i-q.front())*(i-q.front());
                    mark[(start+i)%n] = 1;
                    c[(start+i)%n] = 1;
                    q.pop();
                }
            }
        }
        memcpy(c, cog, sizeof(cog));
        mini = min(mini, dist);
    }
    cout << mini;
}

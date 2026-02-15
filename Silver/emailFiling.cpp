#include <iostream>
#include <queue>
#include <set>
#define f first
#define s second
using namespace std;

int t, m, n, k, lBull, rBull, lCow, rCow, request[100010], num[100010];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> cow;
priority_queue<pair<int, int>> leftover, temp;
pair<int, int> curCow;
bool works;
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> m >> n >> k;
        for (int i = 1; i <= m; i++)
            num[i] = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> request[i];
            num[request[i]]++;
        }
        while(!leftover.empty())
            leftover.pop();
        while(!cow.empty())
            cow.pop();
        while(!temp.empty())
            temp.pop();
        for (int i = 0; i < k; i++)
            cow.push({request[i], i});
        lBull = 1;
        rBull = k;
        lCow = 0;
        rCow = k;
        works = true;
        while (leftover.size()+cow.size() > 0)
        {
            curCow = cow.top();
            cow.pop();
            if (curCow.f >= lBull && curCow.f <= rBull) //valid to go
                num[curCow.f]--;
            while(num[lBull] == 0 && rBull < m)
            {
                lBull++;
                rBull++;
            }
            if (curCow.f > rBull) //to far to be in window
            {
                if (rCow < n)
                {
                    leftover.push({lCow, request[lCow]});
                    
                    while (!cow.empty() && cow.top().second != lCow)
                    {
                        temp.push(cow.top());
                        cow.pop();
                    }
                    if (!cow.empty())
                        cow.pop();
                    while (!temp.empty())
                    {
                        cow.push(temp.top());
                        temp.pop();
                    }
                    
                    //move cow window
                    if (curCow.s > lCow)
                        cow.push(curCow);
                    cow.push({request[rCow], rCow});
                    rCow++;
                    lCow++;
                }
                else
                {
                    works = false;
                    break;
                }
            }
            //how to see when move cow window
            else if (rCow < n)
            {
                cow.push({request[rCow], rCow});
                rCow++;
                if (rCow != n)
                    lCow++;
            }
            else
            {
                while (!leftover.empty() && cow.size() < k)
                {
                    lCow = min(lCow, leftover.top().f);
                    cow.push({leftover.top().s, leftover.top().f});
                    leftover.pop();
                }
            }
        }
        if (works)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
}

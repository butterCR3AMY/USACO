#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#define f first
#define s second
using namespace std;

int n, m, sat, fir, sec, bfs[100010], visited[100010], parent[100010], parentEdge[100010];
pair<int, int> cow[100010];
vector<int> cycle, perm, edges;
vector<pair<int, int>> adj[100010];
bool used[100010], foundCycle;

void processCycle()
{
    for (int i : cycle) //take all
        visited[i] = 2;
    stack<int> sta;
    for (int i = 0; i < cycle.size(); i++)
    {
        used[edges[i]] = true;
        if (cow[edges[i]].f == cycle[i]) //goes in that direction
        {
            perm.push_back(edges[i]);
            sat++;
            while (!sta.empty())
            {
                perm.push_back(sta.top());
                sta.pop();
                sat++;
            }
        }
        else
            sta.push(edges[i]);
    }
    while(!sta.empty())
    {
        perm.push_back(sta.top());
        sta.pop();
        sat++;
    }
}
void doTrees()
{
    queue<int> q;
    for (int u : cycle) //start from cycles
    {
        bfs[u] = 1;
        q.push(u);
    }

    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        
        for (pair<int, int> neighb : adj[x])
        {
            int v = neighb.first;
            int id = neighb.second;

            if (used[id])
                continue;
            if (bfs[v]) //both sides taken
            {
                used[id] = true;
                perm.push_back(id);
                continue;
            }
            //cow will take v either way (1st or 2nd choice) x being taken makes it hafto
            bfs[v] = 1;
            used[id] = true;
            perm.push_back(id);
            sat++;
            q.push(v);
        }
    }
}
void getCycle(int u, int p, int prevEdge)
{
    visited[u] = 1; //looking at rn
    parent[u] = p;
    int v, id, cur;
    for (pair<int, int> neighb : adj[u])
    {
        id = neighb.second;
        v = neighb.first;
        if (id == prevEdge || bfs[v]) //alr went over this same edge (cant go back)
            continue;
        if (visited[v] == 1)
        {
            //cycle
            foundCycle = true;
            cycle.clear();
            edges.clear();
            cur = u;
            while (cur != v)
            {
                cycle.push_back(cur);
                edges.push_back(parentEdge[cur]);
                cur = parent[cur];
            }
            cycle.push_back(cur);
            edges.push_back(id);
            processCycle();
            doTrees();
            return; //now visited[u] would be 2 (done w it)
        }
        else if (visited[v] == 0)
        {
            parent[v] = u;
            parentEdge[v] = id;
            getCycle(v, u, id);
        }
    }
    visited[u] = 2; //done with u
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> fir >> sec;
        cow[i+1].f = fir;
        cow[i+1].s = sec;
        adj[fir].push_back({sec, i+1});
        adj[sec].push_back({fir, i+1});
    }
    for (int i = 1; i <= m; i++)
    {
        if (visited[i])
            continue;
        parent[i] = -1;
        parentEdge[i] = -1;
        foundCycle = false;
        getCycle(i, -1, -1);
        if (!bfs[i] && !foundCycle) //tree = on its own
        {
            cycle.clear();
            cycle.push_back(i);
            bfs[i] = 1;
            doTrees();
        }
    }
    cout << n-sat << '\n';
    for (int i : perm)
        cout << i << '\n';
}

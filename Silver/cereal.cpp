#include <iostream>
#include <vector>
using namespace std;

int n, m, cnt, prevTook, f[100010], sf[100010], taker[100010];
vector<int> ans;
void dfs(int x)
{
    if (taker[f[x]] != -1 && taker[f[x]] > x) //can take from taker
    {
        prevTook = taker[f[x]];
        taker[f[x]] = x;
        dfs(prevTook);
    }
    else if (taker[f[x]] == -1) //fav not taken
        taker[f[x]] = x;
    
    else if (taker[sf[x]] != -1 && taker[sf[x]] > x) //can take from taker
    {
        prevTook = taker[sf[x]];
        taker[sf[x]] = x;
        dfs(prevTook);
    }
    else if (taker[sf[x]] == -1) //fav not taken
        taker[sf[x]] = x;
    else //doesnt get
        cnt--;
}
int main()
{
    freopen("cereal.in", "r", stdin);
    freopen("cereal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> f[i] >> sf[i];
    for (int i = 0; i <= m; i++)
        taker[i] = -1;
    for (int i = n-1; i >= 0; i--)
    {
        //add to front of line
        if (taker[f[i]] != -1 && taker[f[i]] > i) //can take from taker
        {
            prevTook = taker[f[i]];
            taker[f[i]] = i;
            cnt++;
            dfs(prevTook);
        }
        else if (taker[f[i]] == -1) //fav not taken
        {
            taker[f[i]] = i;
            cnt++;
        }
        
        ans.push_back(cnt);
    }
    for (int i = n-1; i >= 0; i--)
        cout << ans[i] << '\n';
}

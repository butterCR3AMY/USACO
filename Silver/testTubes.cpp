#include <iostream>
#include <vector>
using namespace std;

int n, t, p, top1, top2, ans, mt;
string f, s;
vector<pair<int, int>> moves;
vector<int> cur[3];
void reset()
{
    cur[0].clear();
    cur[1].clear();
    cur[2].clear();
    if (f[0] == s[0])
        cur[0].push_back(3-(s[0]-'1'+1));
    for (int i = 0; i < f.length(); i++)
        cur[0].push_back(f[i]-'1'+1);
    for (int i = 0; i < s.length(); i++)
        cur[1].push_back(s[i]-'1'+1);
}
string compress(string s)
{
    string newS = "";
    newS += s[0];
    for (int i = 1; i < s.length(); i++)
        if (s[i] != s[i-1])
            newS += s[i];
    return newS;
}
void move(int a, int b)
{
    moves.push_back({a, b});
    if (cur[b].size() == 0 || cur[b].back() != cur[a].back())
        cur[b].push_back(cur[a].back());
    cur[a].pop_back();
}
int main()
{
    cin >> t;
    while(t--)
    {
        cin >> n >> p >> f >> s;
        f = compress(f);
        s = compress(s);
        reset();
        ans = (int)(cur[0].size()+cur[1].size())-2;
        //needa use beaker
        if (ans > 1)
            ans++;
        cout << ans << '\n';
        if (p == 1)
            continue;
        moves.clear();
        //same last char then pour bigger into smaller
        if (cur[0].back() == cur[1].back())
        {
            if (cur[0].size() > cur[1].size())
                move(0, 1);
            else
                move(1, 0);
        }
        for (int i = 0; i < 2; i++)
        {
            if (cur[i].size() > 1)
            {
                move(i, 2);
                mt = 0;
                //bottomest color of one choosing to empty
                //is same as color of aux tube
                if (cur[mt][0] == cur[2][0])
                    mt = 1-mt;
                while(cur[mt].size() > 1)
                {
                    if (cur[mt].back() == cur[2][0])
                        move(mt, 2);
                    else
                        move(mt, 1-mt);
                }
                mt = 1-mt;
                while (cur[mt].size() > 1)
                {
                    if (cur[mt].back() == cur[2][0])
                        move(mt, 2);
                    else
                        move(mt, 1-mt);
                }
                move(2, mt);
                break;
            }
        }
        for (int i = 0; i < moves.size(); i++)
            cout << moves[i].first+1 << " " << moves[i].second+1 << '\n';
    }
}

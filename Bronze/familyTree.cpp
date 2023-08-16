#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int n;
string familyTree[100][2];
string x, y;
map<string,string> parent;
map<string,set<string>> children;
set<string> cows;

string mother(string cow1, string cow2)
{
    int cnt = 0;
    string possible = "", ans = "";
    string cur = cow2;
    while (parent.count(cur))
    {
        cnt ++;
        if (cnt == 1)
            possible = "mother";
        else if (cnt == 2)
            possible = "grand-mother";
        else
            possible = "great-"+possible;
        if (parent[cur] == cow1)
        {
            ans = possible;
            break;
        }
        cur = parent[cur];
    }
    return ans;
}
string sister(string cow1, string cow2)
{
    int cnt = 0;
    string possible = "", ans = "";
    string cur = cow1;
    while (parent.count(cur))
    {
        cnt ++;
        if (cnt == 1)
            possible = "sister";
        else if (cnt == 2)
            possible = "aunt";
        else
            possible = "great-"+possible;
        if (children[parent[cur]].count(cow2))
        {
            ans = possible;
            break;
        }
        cur = parent[cur];
    }
    return ans;
}
bool notRelated(string cow1, string cow2)
{
    string cur1 = cow1, cur2 = cow2;
    while (parent.count(cur1))
    {
        cur1 = parent[cur1];
    }
    while (parent.count(cur2))
    {
        cur2 = parent[cur2];
    }
    if (cur1 == cur2)
        return false;
    return true;
}
int main()
{
    freopen("family.in", "r", stdin);
    freopen("family.out", "w", stdout);
    cin >> n >> x >> y;
    for (int i = 0; i < n; i++)
    {
        cin >> familyTree[i][0] >> familyTree[i][1];
        cows.insert(familyTree[i][0]);
        cows.insert(familyTree[i][1]);
    }
    for (string cow : cows)
    {
        for (int i = 0; i < n; i++)
        {
            if (familyTree[i][0] == cow)
                children[cow].insert(familyTree[i][1]);
        }
        for (int i = 0; i < n; i++)
        {
            if (familyTree[i][1] == cow)
                parent[cow] = familyTree[i][0];
        }
    }
    if (notRelated(x,y))
    {
        cout << "NOT RELATED" << endl;
        return 0;
    }
    else if (mother(x, y) != "")
    {
        cout << x << " is the " << mother(x,y) << " of " << y << endl;
    }
    else if (mother(y, x) != "")
    {
        cout << y << " is the " << mother(y,x) << " of " << x << endl;
    }
    else if (sister(x, y) == "sister")
    {
        cout << "SIBLINGS" << endl;
    }
    else if (sister(x, y) != "")
    {
        cout << y << " is the " << sister(x,y) << " of " << x << endl;
    }
    else if (sister(y, x) != "")
    {
      cout << x << " is the " << sister(y,x) << " of " << y << endl;
    }
    else
    {
        cout << "COUSINS";
    }
}

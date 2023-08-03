#include <iostream>
#include <vector>
using namespace std;

vector<int> classes;
bool allSame = false;
int n, t, cur, cnt = 0, seq = 0, len = 0, mini = 10000000;
int main()
{
    cin >> t;
    while(t--)
    {
        cin >> n;
        mini = 10000000;
        cnt = 0;
        allSame = false;
        seq = 0;
        classes.clear();
        for (int i = 0; i < n; i++)
        {
            cin >> cur;
            cnt += cur;
            classes.push_back(cur);
        }
        for (int i = 1; i < n; i++)
        {
            if (classes[i] != classes[i-1])
                break;
            if (i == n-1)
                allSame = true;
        }
        if (allSame)
        {
            cout << 0 << endl;
            continue;
        }
        for (int j = 1; j <= cnt; j++)
        {
            if (cnt % j != 0)
                continue;
            cur = 0;
            len = 0;
            seq = 0;
            for (int i = 0; i < n; i++)
            {
                if (seq == j)
                {
                    cur += len-1;
                    len = 0;
                    seq = 0;
                }
                seq += classes[i];
                len ++;
            }
            if (seq != j)
                continue;
            cur += len-1;
            if (cur < mini)
                mini = cur;
        }
        cout << mini << endl;
    }
}

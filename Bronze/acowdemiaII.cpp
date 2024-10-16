#include <iostream>
#include <map>
using namespace std;
//#define THIS

#ifdef THIS
char ans[100][100];
int main()
{
    map<string, int> m;
    bool sequence = true;
    int n, k;
    cin >> k >> n;
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < n; j++)
//            ans[i][j] = '?';
//    }
    string members[n], list[n];
    for (int i = 0; i < n; i++)
        cin >> members[i];
    for (int q = 0; q < k; q++)
    {
        m.clear();
        for (int i = 0; i < n; i++)
        {
            cin >> list[i];
            m[list[i]] = i;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                sequence = true;
                if (i == j)
                {
                    ans[i][j] = 'B';
                    continue;
                }
                else if (m[members[i]] < m[members[j]])
                {
                    int last = m[members[j]];
                    for (int k = m[members[i]]; k < last; k++)
                    {
                        if (list[k] > list[k+1])
                            sequence = false;
                    }
                    if (ans[i][j] != '0' && ans[i][j] != '1' && sequence == false)
                        ans[i][j] = '0';
                }
                else if (m[members[i]] > m[members[j]])
                {
                    int last = m[members[j]];
                    for (int k = m[members[i]]; k > last; k--)
                    {
                        if (list[k] < list[k-1])
                            sequence = false;
                    }
                    if (ans[i][j] != '0' && ans[i][j] != '1' && sequence == false)
                        ans[i][j] = '1';
                }
            }
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (ans[i][j] != '0' && ans[i][j] != '1' && ans[i][j] != 'B')
                cout << '?';
            else
                cout << ans[i][j];
        }
        cout << endl;
    }
}
#endif

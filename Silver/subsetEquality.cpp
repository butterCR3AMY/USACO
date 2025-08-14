#include <iostream>
#include <vector>
using namespace std;

string s, t, cur, str1, str2;
int n1, n2, m, q, numS[26], numT[26];
vector<int> posS[26], posT[26];
bool works, work[26][26];
int main()
{
    cin >> s >> t;
    cin >> q;
    n1 = (int)s.length();
    n2 = (int)t.length();
    for (int i = 0; i < n1; i++)
    {
        numS[s[i]-'a']++;
        posS[s[i]-'a'].push_back(i);
    }
    for (int i = 0; i < n2; i++)
    {
        numT[t[i]-'a']++;
        posT[t[i]-'a'].push_back(i);
    }
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (i == j)
            {
                work[i][j] = true;
                continue;
            }
            if (numT[i] != numS[i] || numT[j] != numS[j])
            {
                work[i][j] = false;
                continue;
            }
            str1 = "";
            str2 = "";
            for (int k = 0; k < n1; k++)
            {
                if (s[k] == (char)('a'+i))
                    str1 += (char)('a'+i);
                if (s[k] == (char)('a'+j))
                    str1 += (char)('a'+j);
            }
            for (int k = 0; k < n2; k++)
            {
                if (t[k] == (char)('a'+i))
                    str2 += (char)('a'+i);
                if (t[k] == (char)('a'+j))
                    str2 += (char)('a'+j);
            }
            if (str1 == str2)
                work[i][j] = true;
            else
                work[i][j] = false;
        }
    }
    while (q--)
    {
        cin >> cur;
        m = (int)cur.length();
        works = true;
        for (int i = 0; i < m; i++)
        {
            if (numS[cur[i]-'a'] != numT[cur[i]-'a'])
                works = false;
        }
        if (!works)
        {
            cout << 'N';
            continue;
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < m; j++)
            {
                works = works && work[cur[i]-'a'][cur[j]-'a'];
            }
        }
        if (works)
            cout << 'Y';
        else
            cout << 'N';
    }
}

//
//  FEB.cpp
//  Bronze Problems
//
//  Created by Rebeca Costin on 7/14/23.
//

#include <iostream>
using namespace std;
//#define THIS

#ifdef THIS
char l[100010], r[100010];
int sz[100010];
int main()
{
    int n, indx = -1;
    cin >> n;
    string s;
    cin >> s;
    
    for (int i = 0; i < n; i++)
    {
        if (i == 0 && s[i] == 'F')
        {
            indx ++;
            l[indx] = 'X';
        }
        if (i > 0 && s[i] == 'F' && s[i-1] != 'F')
        {
            indx ++;
            l[indx] = s[i-1];
        }
        if (i == n-1 && s[i] == 'F')
        {
            r[indx] = 'X';
        }
        if (i < n-1 && s[i] == 'F' && s[i+1] != 'F')
        {
            r[indx] = s[i+1];
        }
        if (s[i] == 'F')
        {
            sz[indx] ++;
        }
    }
    int mini = 0, maxi = 0, inc = 2;
    for (int i = 0; i < n-1; i++)
    {
        if (s[i] == s[i+1] && s[i] != 'F')
        {
            mini ++;
            maxi ++;
        }
    }
    if (s[0] == 'F' || s[n-1] == 'F')
        inc = 1;
    for (int i = 0; i <= indx; i++)
    {
        if (l[i] != r[i] && (l[i] == 'X' || r[i] == 'X'))
        {
            mini += 0;
            maxi += sz[i];
        }
        else if (l[i] == r[i] && l[i] == 'X')
        {
            mini += 0;
            maxi += sz[i]-1;
        }
        else if (sz[i]%2 == 0)
        {
            if (l[i] != r[i])
            {
                mini += 0;
                maxi += sz[i];
            }
            if (l[i] == r[i])
            {
                mini += 1;
                maxi += sz[i]+1;
            }
        }
        else
        {
            if (l[i] != r[i])
            {
                mini += 1;
                maxi += sz[i];
            }
            if (l[i] == r[i])
            {
                mini += 0;
                maxi += sz[i]+1;
            }
        }
    }
    cout << ((maxi-mini)/inc)+1 << endl;
    for (int i = mini; i <= maxi; i+= inc)
    {
        cout << i << '\n';
    }
    
}
#endif

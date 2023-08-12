#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool allZeros = true;
int n, len = 0, mini = 100010, maxi = 0, previ, ans = 0, edge1, edge2, prev1 = -1;
string cows;
vector<int> seqLens;
int main()
{
    freopen("socdist1.in", "r", stdin);
    freopen("socdist1.out", "w", stdout);
    cin >> n;
    cin >> cows;
    for (int i = 0; i < n; i++)
    {
        if (cows[i] == '1')
        {
            edge1 = i;
            break;
        }
    }
    for (int i = n-1; i >= 0; i--)
    {
        if (cows[i] == '1')
        {
            edge2 = n-1-i;
            break;
        }
    }
    for (int i = edge1; i <= n-1-edge2; i++)
    {
        if (cows[i] == '0')
        {
            len ++;
        }
        if (i > 0 && cows[i-1] == '0' && cows[i] == '1')
        {
//            if (len < mini)
//            {
//                mini = len;
//            }
            if (len > maxi)
            {
                previ = maxi;
                maxi = len;
            }
            else if (len > previ)
            {
                previ = len;
            }
            len = 0;
        }
        if (i == n-1)
        {
//            if (len < mini)
//            {
//                mini = len;
//            }
            if (len > maxi)
            {
                previ = maxi;
                maxi = len;
            }
            else if (len > previ)
            {
                previ = len;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (cows[i] == '1' && prev1 != -1)
        {
            if ((i-prev1)< mini)
                mini = i-prev1;
        }
        if (cows[i] == '1')
            prev1 = i;
    }
    for (int i = 0; i < n; i++)
    {
        if (cows[i] == '1')
            allZeros = false;
    }
    if (allZeros)
        cout << n-1;
    else
        cout << min(max({(maxi-2)/3+1, min((maxi-1)/2+1, (previ-1)/2+1), min((maxi-1)/2+1, edge1), min((maxi-1)/2+1, edge2), min(edge1, edge2), (edge1-2)/2+1, (edge2-2)/2+1}), mini);
}

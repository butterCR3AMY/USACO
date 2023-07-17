#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
#define input() ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//#define THIS
typedef long long ll;

#ifdef THIS
long long nx[500010];
int last[2];
int main()
{
    input();
    int n;
    ll count = 0;
    cin >> n;
    nx[n] = n;
    string cows;
    cin >> cows;
    last[0] = n;
    last[1] = n;
    for (int i = n-1; i >= 0; i--)
    {
        last[cows[i]-'G'] = i;
        nx[i] = last[1-(cows[i]-'G')];
    }
    for (int i = 0; i <= n-3; i++)
    {
        if (cows[i] == cows[i+1])
        {
            long long h1 = nx[i+1];
            
            if (nx[h1] - h1 > 1)
                count ++;
            if (nx[h1] - h1 == 1)
                count += nx[nx[h1]]-h1;
        }
        if (cows[i] != cows[i+1])
        {
            if (cows[i+2] == cows[i+1])
                count += nx[i+2]-i-2;
            if (cows[i+2] == cows[i])
                count += nx[i+2]-nx[i]-1;
        }
    }
    cout << count << endl;
    // GGGGGHG
    // GHHHHHG
    // GHGGGGH
}
#endif

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool notAllSame = false;
int n, cnt = 0;
char prev1 = 'O', prev2 = 'O', last1 = '0', last2 = '0';
string cows;
int main()
{
    cin >> n >> cows;
    for (int i = 0; i < n; i+= 2)
    {
        if (cows[i] == cows[i+1])
        {
            continue;
        }
        notAllSame = true;
        if (i > 0)
        {
            if ((cows[i] == 'G' && cows[i+1] == 'H') && (prev1 == 'H' && prev2 == 'G'))
            {
                cnt ++;
            }
            if ((cows[i] == 'H' && cows[i+1] == 'G') && (prev1 == 'G' && prev2 == 'H'))
            {
                cnt ++;
            }
        }
        last1 = cows[i];
        last2 = cows[i+1];
        prev1 = cows[i];
        prev2 = cows[i+1];
    }
    if (notAllSame)
        cnt ++;
    if (last1 == 'H' && last2 == 'G')
        cnt --;
    cout << cnt;
}
/*
 GH|GH|HG|HG|HG|
 */

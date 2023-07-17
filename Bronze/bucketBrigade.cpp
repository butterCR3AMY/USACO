//
//  bucketBrigade.cpp
//  Bronze Problems
//
//  Created by Rebeca Costin on 7/17/23.
//

#include <iostream>
#include <cmath>
#include <fstream>
#include <algorithm>
using namespace std;
#define THIS
string arr[10];
#ifdef THIS
int main()
{
    freopen ("buckets.in", "r", stdin);
    freopen ("buckets.out", "w", stdout);
    int barnr, barnc, laker, lakec, rockr, rockc;
    for (int i = 0; i < 10; i++)
        cin >> arr[i];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (arr[i][j] == 'B')
            {
                barnr = i;
                barnc = j;
            }
            if (arr[i][j] == 'L')
            {
                laker = i;
                lakec = j;
            }
            if (arr[i][j] == 'R')
            {
                rockr = i;
                rockc = j;
            }
        }
    }
    if (abs(laker-barnr) == 0 && rockr == laker && max(lakec, barnc) > rockc && min(barnc, lakec) < rockc)
    {
        cout << abs(laker-barnr)+abs(lakec-barnc)+1 << endl;
    }
    else if (abs(lakec-barnc) == 0 && rockc == lakec && max(laker, barnr) > rockr && min(barnr, laker) < rockr)
    {
        cout << abs(laker-barnr)+abs(lakec-barnc)+1 << endl;
    }
    else cout << abs(laker-barnr)+abs(lakec-barnc)-1 << endl;
}
#endif

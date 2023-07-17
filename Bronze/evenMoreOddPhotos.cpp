//
//  evenMoreOddPhotos.cpp
//  Bronze Problems
//
//  Created by Rebeca Costin on 7/17/23.
//


#include <iostream>
using namespace std;
//#define THIS

#ifdef THIS
int main()
{
    int even = 0, odd = 0, n, cur, curParity = 0, groups = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> cur;
        if (cur%2 == 0)
            even ++;
        else
            odd ++;
    }
    while (true)
    {
        if (curParity == 0)
        {
            if (even > 0)
            {
                even --;
                groups ++;
            }
            else if (odd > 1)
            {
                odd -= 2;
                groups ++;
            }
            else if (odd == 1)
            {
                groups --;
                break;
            }
        }
        else
        {
            if (odd > 0)
            {
                odd --;
                groups ++;
            }
            else
            {
                break;
            }
        }
        curParity = 1-curParity;
    }
    cout << groups << endl;
}
#endif

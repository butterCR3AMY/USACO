#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
//#define THIS

#ifdef THIS
int main()
{
    int n, cw;
    string cur;
    cin >> n;
    while(n--)
    {
        cin >> cur;
        cw = 0;
        for (int j = 1; j < cur.length(); j++)
        {
            if (cur[j] == 'N' && cur[j-1] == 'E')
                cw --;
            else if (cur[j] == 'E' && cur[j-1] == 'S')
                cw --;
            else if (cur[j] == 'S' && cur[j-1] == 'W')
                cw --;
            else if (cur[j] == 'W' && cur[j-1] == 'N')
                cw --;
            else if (cur[j] != cur[j-1])
            {
                cw ++;
            }
        }
        if (cw > 0)
            cout << "CW" << endl;
        else
            cout << "CCW" << endl;
    }
}
#endif

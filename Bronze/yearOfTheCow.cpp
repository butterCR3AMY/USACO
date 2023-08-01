#include <iostream>
using namespace std;
#include <cmath>
#include <set>
#include <algorithm>
//#define THIS

#ifdef THIS

string years[12] = {"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};
string prevCows[110];
int prevYears[110];
int prevDifs[110];
int main()
{
    prevCows[0] = "Bessie";
    prevYears[0] = 0;
    
    int n, pos = 0;
    string notNeeded, s, year, curCow, curCowFrom;
    cin >> n;
    for (int q = 1; q <= n; q++)
    {
        cin >> curCow;
        prevCows[q] = curCow;
        for (int i = 0; i < 2; i++)
            cin >> notNeeded;
        cin >> s >> year;
        for (int i = 0; i < 2; i++)
            cin >> notNeeded;
        cin >> curCowFrom;
        if (s == "previous")
        {
            for (int i = 0; i <= 100; i++)
            {
                if (prevCows[i] == curCowFrom)
                {
                    pos = i;
                    break;
                }
                
            }
            for (int i = 0; i < 12; i++)
            {
                if (years[i] == year)
                {
                    prevYears[q] = i;
                    if (i >= prevYears[pos])
                        prevDifs[q] = -(12-i+prevYears[pos])+prevDifs[pos];
                    else
                        prevDifs[q] = i-prevYears[pos]+prevDifs[pos];
                }
                
            }
            
        }
        else
        {
            for (int i = 0; i <= 100; i++)
            {
                if (prevCows[i] == curCowFrom)
                {
                    pos = i;
                    break;
                }
                
            }
            for (int i = 0; i < 12; i++)
            {
                if (years[i] == year)
                {
                    prevYears[q] = i;
                    if (i > prevYears[pos])
                        prevDifs[q] = i-prevYears[pos]+prevDifs[pos];
                    else
                        prevDifs[q] = 12+i-prevYears[pos]+prevDifs[pos];
                }
                
            }
        }
        if (curCow == "Elsie")
        {
            cout << abs(prevDifs[q]);
            break;
        }
    }
}
#endif

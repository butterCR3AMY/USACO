#include <iostream>
#include <fstream>
#include <set>
using namespace std;
//#define THIS

#ifdef THIS
set <int> answers;
int barn1[10], barn2[10];
int main()
{
    freopen ("backforth.in", "r", stdin);
    freopen ("backforth.out", "w", stdout);
    for(int i = 0; i < 10; i++)
        cin >> barn1[i];
    for(int i = 0; i < 10; i++)
        cin >> barn2[i];
    int a, b, c, d;
    for (int i = 0; i < 10; i++)
    {
        a = barn1[i];
        for (int j = 0; j < 11; j++)
        {
            if (j == 10)
                b = a;
            else
                b = barn2[j];
            for (int k = 0; k < 11; k++)
            {
                if (k == 10)
                    c = b;
                else if (k == i && j != 10)
                    continue;
                else
                    c = barn1[k];
                for (int l = 0; l < 11; l++)
                {
                    if (l == 10)
                        d = c;
                    else if (l == j && k != 10)
                        continue;
                    else
                        d = barn2[l];
                    answers.insert((1000-a+b-c+d));
                }
            }
        }
    }
    cout << (answers.size());
}
#endif

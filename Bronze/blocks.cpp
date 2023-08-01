#include <iostream>
#include <set>
using namespace std;
//#define THIS

#ifdef THIS
set<string> words;
string blocks[4], cur = "", curWord;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < 4; i++)
    {
        cin >> blocks[i];
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                for (int l = 0; l < 4; l++)
                {
                    if (i == j || j == k || k == l || j == l || i == k || i == l)
                    {
                        continue;
                    }
                    for (int a = 0; a < 6; a++)
                    {
                        for (int b = 0; b < 6; b++)
                        {
                            for (int c = 0; c < 6; c++)
                            {
                                for (int d = 0; d < 6; d++)
                                {
                                    cur = "";
                                    cur += blocks[i][a];
                                    words.insert(cur);
                                    cur += blocks[j][b];
                                    words.insert(cur);
                                    cur += blocks[k][c];
                                    words.insert(cur);
                                    cur += blocks[l][d];
                                    words.insert(cur);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cin >> curWord;
        if (words.count(curWord) > 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    
}
#endif

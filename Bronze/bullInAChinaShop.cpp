//Bull in a China Shop
#include <iostream>
#include <vector>
using namespace std;

bool works, done;
int n, k;
string pieces[10][8];
char after[8][8], og[8][8];
bool outofbounds(int x)
{
    if (x < 0 || x >= n)
        return true;
    return false;
}
int main()
{
    freopen("bcs.in", "r", stdin);
    freopen("bcs.out", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> og[i][j];
        }
    }
    for (int t = 0; t < k; t++)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> pieces[t][i];
        }
    }
    // first piece
    for (int t1 = 0; t1 < k; t1++)
    {
        // second piece
        for (int t2 = 0; t2 < k; t2++)
        {
            if (t1 == t2)
                continue;
            // try all the diff shifts for piece 1
            for (int shifti1 = -1*n; shifti1 <= n; shifti1++)
            {
                for (int shiftj1 = -1*n; shiftj1 <= n; shiftj1++)
                {
                    // try all the diff shifts for piece 2
                    for (int shifti2 = -1*n; shifti2 <= n; shifti2++)
                    {
                        for (int shiftj2 = -1*n; shiftj2 <= n; shiftj2++)
                        {
                            works = true;
                            done = true;
                            // reset after
                            for (int i = 0; i < n; i++)
                            {
                                for (int j = 0; j < n; j++)
                                {
                                    after[i][j] = '.';
                                }
                            }
                            // try to put piece 1 into after
                            for (int i = 0; i < n; i++)
                            {
                                for (int j = 0; j < n; j++)
                                {
                                    if (pieces[t1][i][j] == '.')
                                        continue;
                                    if (outofbounds(i+shifti1) || outofbounds(j+shiftj1))
                                    {
                                        works = false;
                                        continue;
                                    }
                                    after[i+shifti1][j+shiftj1] = pieces[t1][i][j];
                                }
                            }

                            // try to put piece 2 into after
                            for (int i = 0; i < n; i++)
                            {
                                for (int j = 0; j < n; j++)
                                {
                                    if (pieces[t2][i][j] == '.')
                                        continue;
                                    if (outofbounds(i+shifti2) || outofbounds(j+shiftj2))
                                    {
                                        works = false;
                                        continue;
                                    }
                                    if (after[i+shifti2][j+shiftj2] == '#')
                                    {
                                        works = false;
                                        continue;
                                    }
                                    after[i+shifti2][j+shiftj2] = pieces[t2][i][j];
                                }
                            }
                            if (!works)
                                continue;
                            for (int i = 0; i < n; i++)
                            {
                                for (int j = 0; j < n; j++)
                                {
                                    if (after[i][j] != og[i][j])
                                        done = false;
                                }
                            }
                            if (done)
                            {
                                cout << min(t1+1, t2+1) << " " << max(t1+1, t2+1) << '\n';
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
}

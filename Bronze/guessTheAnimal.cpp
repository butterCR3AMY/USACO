#include <iostream>
using namespace std;

int n, numChars, k[100], common, maxi = 0;
string animalChars[100][100], animal;
int main()
{
    freopen("guess.in", "r", stdin);
    freopen("guess.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> animal;
        cin >> numChars;
        k[i] = numChars;
        for (int j = 0; j < numChars; j++)
        {
            cin >> animalChars[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int l = i+1; l < n; l++)
        {
            common = 0;
            for (int j = 0; j < k[i]; j++)
            {
                for (int m = 0; m < k[l]; m++)
                {
                    if (animalChars[i][j] == animalChars[l][m])
                    {
                        common ++;
                    }
                }

            }
            if (common+1 > maxi)
                maxi = common+1;
        }
    }
    cout << maxi << endl;
}

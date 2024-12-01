#include <iostream>
#include <algorithm>
using namespace std;

int cnt, cnt2, indR[3], indC[3];
string board[3], row;
char cur, t1, t2;
bool found, works[3], yes, diag1 = false, diag2 = false;
int main()
{
    freopen("tttt.in", "r", stdin);
    freopen("tttt.out", "w", stdout);
    for (int i = 0; i < 3; i++)
        cin >> board[i];
    //check individuals
    for (int ind = 0; ind < 26; ind++)
    {
        cur = (char)('A'+ind);
        found = false;
        //rows
        row = "";
        for (int i = 0; i < 3; i++)
            row += cur;
        for (int i = 0; i < 3; i++)
        {
            if (board[i] == row)
            {
                found = true;
                indR[i] = 1;
            }
        }
        //columns
        for (int i = 0; i < 3; i++)
            works[i] = true;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] != cur)
                    works[j] = false;
            }
        }
        for (int i = 0; i < 3; i++)
        {
            if (works[i])
            {
                indC[i] = 1;
                found = true;
            }
        }
        //diagonals
        if (board[0][0] == cur && board[1][1] == cur && board[2][2] == cur)
        {
            diag1 = true;
            found = true;
        }
        if (board[0][2] == cur && board[1][1] == cur && board[2][0] == cur)
        {
            diag2 = true;
            found = true;
        }
        if (found)
            cnt++;
    }
    //check teams
    for (int T1 = 0; T1 < 26; T1++)
    {
        for (int T2 = 0; T2 < 26; T2++)
        {
            if (T1 >= T2)
                continue;
            t1 = (char)(T1+'A');
            t2 = (char)(T2+'A');
            found = false;
            //rows
            for (int i = 0; i < 3; i++)
            {
                if (indR[i])
                    continue;
                yes = true;
                for (int j = 0; j < 3; j++)
                {
                    if (board[i][j] != t1 && board[i][j] != t2)
                        yes = false;
                }
                if (yes)
                    found = true;
            }
            //columns
            for (int i = 0; i < 3; i++)
            {
                if (indC[i])
                    continue;
                yes = true;
                for (int j = 0; j < 3; j++)
                {
                    if (board[j][i] != t1 && board[j][i] != t2)
                        yes = false;
                }
                if (yes)
                    found = true;
            }
            //diagonals
            yes = true;
            for (int i = 0; i < 3; i++)
            {
                if (board[i][i] != t1 && board[i][i] != t2)
                {
                    yes = false;
                }
            }
            if (yes && !diag1)
                found = true;
            yes = true;
            for (int i = 0; i < 3; i++)
            {
                if (board[2-i][i] != t1 && board[2-i][i] != t2)
                    yes = false;
            }
            if (yes && !diag2)
                found = true;
            if (found)
                cnt2++;
        }
    }
    cout << cnt << '\n' << cnt2;
}

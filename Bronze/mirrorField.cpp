#include <iostream>
using namespace std;

int n, m, curI, curJ, cur, maxi;
string board[1000];
char dir;
int main()
{
    freopen("mirror.in", "r", stdin);
    freopen("mirror.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> board[i];
    //down from up
    for (int j = 0; j < m; j++)
    {
        dir = 'D';
        curI = 0;
        curJ = j;
        cur = 0;
        while(curI >= 0 && curI < n && curJ >= 0 && curJ < m)
        {
            if (dir == 'D')
            {
                if (board[curI][curJ] == '/')
                {
                    dir = 'L';
                    curJ--;
                }
                else
                {
                    dir = 'R';
                    curJ++;
                }
            }
            else if (dir == 'U')
            {
                if (board[curI][curJ] == '/')
                {
                    dir = 'R';
                    curJ++;
                }
                else
                {
                    dir = 'L';
                    curJ--;
                }
            }
            else if (dir == 'L')
            {
                if (board[curI][curJ] == '/')
                {
                    dir = 'D';
                    curI++;
                }
                else
                {
                    dir = 'U';
                    curI--;
                }
            }
            else if (dir == 'R')
            {
                if (board[curI][curJ] == '/')
                {
                    dir = 'U';
                    curI--;
                }
                else
                {
                    dir = 'D';
                    curI++;
                }
            }
            cur++;
        }
        maxi = max(maxi, cur);
    }
    //up from down
    for (int j = 0; j < m; j++)
    {
        dir = 'U';
        curI = n-1;
        curJ = j;
        cur = 0;
        while(curI >= 0 && curI < n && curJ >= 0 && curJ < m)
        {
            if (dir == 'D')
            {
                if (board[curI][curJ] == '/')
                {
                    dir = 'L';
                    curJ--;
                }
                else
                {
                    dir = 'R';
                    curJ++;
                }
            }
            else if (dir == 'U')
            {
                if (board[curI][curJ] == '/')
                {
                    dir = 'R';
                    curJ++;
                }
                else
                {
                    dir = 'L';
                    curJ--;
                }
            }
            else if (dir == 'L')
            {
                if (board[curI][curJ] == '/')
                {
                    dir = 'D';
                    curI++;
                }
                else
                {
                    dir = 'U';
                    curI--;
                }
            }
            else if (dir == 'R')
            {
                if (board[curI][curJ] == '/')
                {
                    dir = 'U';
                    curI--;
                }
                else
                {
                    dir = 'D';
                    curI++;
                }
            }
            cur++;
        }
        maxi = max(maxi, cur);
    }
    //right from left
    for (int i = 0; i < n; i++)
    {
        dir = 'R';
        curI = i;
        curJ = 0;
        cur = 0;
        while(curI >= 0 && curI < n && curJ >= 0 && curJ < m)
        {
            if (dir == 'D')
            {
                if (board[curI][curJ] == '/')
                {
                    dir = 'L';
                    curJ--;
                }
                else
                {
                    dir = 'R';
                    curJ++;
                }
            }
            else if (dir == 'U')
            {
                if (board[curI][curJ] == '/')
                {
                    dir = 'R';
                    curJ++;
                }
                else
                {
                    dir = 'L';
                    curJ--;
                }
            }
            else if (dir == 'L')
            {
                if (board[curI][curJ] == '/')
                {
                    dir = 'D';
                    curI++;
                }
                else
                {
                    dir = 'U';
                    curI--;
                }
            }
            else if (dir == 'R')
            {
                if (board[curI][curJ] == '/')
                {
                    dir = 'U';
                    curI--;
                }
                else
                {
                    dir = 'D';
                    curI++;
                }
            }
            cur++;
        }
        maxi = max(maxi, cur);
    }
    //left from right
    for (int i = 0; i < n; i++)
    {
        dir = 'L';
        curI = i;
        curJ = m-1;
        cur = 0;
        while(curI >= 0 && curI < n && curJ >= 0 && curJ < m)
        {
            if (dir == 'D')
            {
                if (board[curI][curJ] == '/')
                {
                    dir = 'L';
                    curJ--;
                }
                else
                {
                    dir = 'R';
                    curJ++;
                }
            }
            else if (dir == 'U')
            {
                if (board[curI][curJ] == '/')
                {
                    dir = 'R';
                    curJ++;
                }
                else
                {
                    dir = 'L';
                    curJ--;
                }
            }
            else if (dir == 'L')
            {
                if (board[curI][curJ] == '/')
                {
                    dir = 'D';
                    curI++;
                }
                else
                {
                    dir = 'U';
                    curI--;
                }
            }
            else if (dir == 'R')
            {
                if (board[curI][curJ] == '/')
                {
                    dir = 'U';
                    curI--;
                }
                else
                {
                    dir = 'D';
                    curI++;
                }
            }
            cur++;
        }
        maxi = max(maxi, cur);
    }
    cout << maxi;
}

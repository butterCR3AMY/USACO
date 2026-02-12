#include <iostream>
#include <map>
#include <set>
using namespace std;

int n, ans, nxtInt, xd[4] = {-1, 1, 0, 0}, yd[4] = {0, 0, -1, 1};
int vis[25][25][19683];
char arr[30][30];
string board[25], nxtStr;
set<string> s;
void insertStr(string str, char ch, int r, int c)
{
    int pos;
    pos = 3*(r-1)+c-1;
    if (str[pos] != '.')
    {
        nxtStr = str;
        return;
    }
    string newStr = "";
    for (int i = 0; i < pos; i++)
        newStr += str[i];
    newStr += ch;
    for (int i = pos+1; i < 9; i++)
        newStr += str[i];
    nxtStr = newStr;
}
bool full(string str)
{
    for (int i = 0; i < 9; i++)
    {
        if (str[i] == '.')
            return false;
    }
    return true;
}
bool checkMoo(string str)
{
    string row1 = "", row2 = "", row3 = "", col1 = "", col2 = "", col3 = "", diag1 = "", diag2 = "";
    //check for horizontal moos & ooms
    for (int i = 0; i < 3; i++)
        row1 += str[i];
    for (int i = 3; i < 6; i++)
        row2 += str[i];
    for (int i = 6; i < 9; i++)
        row3 += str[i];
    if (row1 == "MOO" || row1 == "OOM" || row2 == "MOO" || row2 == "OOM" || row3 == "MOO" || row3 == "OOM")
    {
        s.insert(str);
        return true;
    }
    //check for vertical moos & ooms
    for (int i = 0; i < 7 ; i+= 3)
        col1 += str[i];
    for (int i = 1; i < 8; i+= 3)
        col2 += str[i];
    for (int i = 2; i < 9; i+= 3)
        col3 += str[i];
    if (col1 == "MOO" || col1 == "OOM" || col2 == "MOO" || col2 == "OOM" || col3 == "MOO" || col3 == "OOM")
    {
        s.insert(str);
        return true;
    }
    //check for diagonal moos
    diag1 += str[0];
    diag1 += str[4];
    diag1 += str[8];
    diag2 += str[2];
    diag2 += str[4];
    diag2 += str[6];
    if (diag1 == "MOO" || diag1 == "OOM" || diag2 == "MOO" || diag2 == "OOM")
    {
        s.insert(str);
        return true;
    }
    return false;
}
void getNxtInt()
{
    //convert nxtStr to nxtInt
    nxtInt = 0;
    int pow3 = 1;
    for (int i = 8; i >= 0; i--)
    {
        if(nxtStr[i] == '.')
            nxtInt += 0;
        if (nxtStr[i] == 'O')
            nxtInt += pow3;
        if (nxtStr[i] == 'M')
            nxtInt += pow3*2;
        pow3 *= 3;
    }
}
void go(int r, int c, string str)
{
    if (checkMoo(str))
        return;
    if (full(str))
        return;
    int nxtR, nxtC;
    for (int k = 0; k < 4; k++)
    {
        nxtR = r+xd[k];
        nxtC = c+yd[k];
        if (nxtR >= 0 && nxtR < n && nxtC >= 0 && nxtC < n && arr[nxtR][nxtC] != '#')
        {
            if (arr[nxtR][nxtC] == '.' || arr[nxtR][nxtC] == 'B')
                nxtStr = str;
            if (arr[nxtR][nxtC] == 'O')
                insertStr(str, 'O', board[nxtR][nxtC*3+1]-'0', board[nxtR][nxtC*3+2]-'0');
            if (arr[nxtR][nxtC] == 'M')
                insertStr(str, 'M', board[nxtR][nxtC*3+1]-'0', board[nxtR][nxtC*3+2]-'0');
            getNxtInt();
            if (vis[nxtR][nxtC][nxtInt] == 1)
                continue;
            vis[nxtR][nxtC][nxtInt] = 1;
            go(nxtR, nxtC, nxtStr);
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> board[i];
        for (int j = 0; j < 3*n; j+=3)
            arr[i][j/3] = board[i][j];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 'B')
            {
                vis[i][j][0] = 1;
                go(i, j, ".........");
                break;
            }
        }
    }
    cout << s.size();
}

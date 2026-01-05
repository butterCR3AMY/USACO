#include <iostream>
#include <vector>
using namespace std;

int n, q, r, c, ans, board[1000][1000], xd[4] = {-1, 1, 0, 0}, yd[4] = {0, 0, -1, 1};
char dir[200010], show[1000][1000];
pair<int, int> inp[200010];
vector<int> res;
bool inRange (int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= n)
        return false;
    return true;
}
void findAll(int i, int j)
{
    if (inRange(i, j-1) && (show[i][j-1] == 'R' || show[i][j-1] == '?') && board[i][j-1] == 0)
    {
        board[i][j-1] = 1;
        ans++;
        findAll(i, j-1);
    }
    if (inRange(i, j+1) && (show[i][j+1] == 'L' || show[i][j+1] == '?') && board[i][j+1] == 0)
    {
        board[i][j+1] = 1;
        ans++;
        findAll(i, j+1);
    }
    if (inRange(i-1, j) && (show[i-1][j] == 'D' || show[i-1][j] == '?') && board[i-1][j] == 0)
    {
        board[i-1][j] = 1;
        ans++;
        findAll(i-1, j);
    }
    if (inRange(i+1, j) && (show[i+1][j] == 'U' || show[i+1][j] == '?') && board[i+1][j] == 0)
    {
        board[i+1][j] = 1;
        ans++;
        findAll(i+1, j);
    }
}
int main()
{
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            show[i][j] = '?';
    }
    for (int i = 0; i < q; i++)
    {
        cin >> r >> c >> dir[i];
        r--;
        c--;
        inp[i].first = r;
        inp[i].second = c;
        show[r][c] = dir[i];
    }
    //top edge
    for (int j = 0; j < n; j++)
    {
        if ((show[0][j] == 'U' || show[0][j] == '?') && board[0][j] == 0)
        {
            board[0][j] = 1;
            ans++;
            findAll(0, j);
        }
    }
    //bottom edge
    for (int j = 0; j < n; j++)
    {
        if ((show[n-1][j] == 'D' || show[n-1][j] == '?') && board[n-1][j] == 0)
        {
            board[n-1][j] = 1;
            ans++;
            findAll(n-1, j);
        }
    }
    //left edge
    for (int i = 0; i < n; i++)
    {
        if ((show[i][0] == 'L' || show[i][0] == '?') && board[i][0] == 0)
        {
            board[i][0] = 1;
            ans++;
            findAll(i, 0);
        }
    }
    //right edge
    for (int i = 0; i < n; i++)
    {
        if ((show[i][n-1] == 'R' || show[i][n-1] == '?') && board[i][n-1] == 0)
        {
            board[i][n-1] = 1;
            ans++;
            findAll(i, n-1);
        }
    }
    //go thru q's backwards
    for (int t = q-1; t>= 0; t--)
    {
        res.push_back(n*n-ans);
        r = inp[t].first;
        c = inp[t].second;
        show[r][c] = '?';
        if (board[r][c] == 1) //alr free
            continue;
        for (int k = 0; k < 4; k++)
        {
            if ((inRange(r+xd[k], c+yd[k]) && board[r+xd[k]][c+yd[k]] == 1) || !inRange(r+xd[k], c+yd[k])) //going into free or edge
            {
                ans++;
                board[r][c] = 1;
                findAll(r, c);
                break;
            }
        }
    }
    for (int i = q-1; i >= 0; i--)
        cout << res[i] << '\n';
}

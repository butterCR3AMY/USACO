#include <iostream>
using namespace std;
//#define THIS
int papers[100000], n, L, curL, cnt;
int bs(int l, int r)
{
    if (l == r)
        return l;
    int mid = (l+r+1)/2;
    curL = L;
    cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (curL > 0 && mid-papers[i] == 1)
        {
            curL--;
            cnt ++;
        }
        else if (papers[i] >= mid)
        {
            cnt ++;
        }
    }
    if (cnt >= mid)
    {
        return bs(mid, r);
    }
    return bs(l, mid-1);
}
#ifdef THIS
int main()
{
    cin >> n >> L;
    for (int i = 0; i < n; i++)
        cin >> papers[i];
    cout << bs(0, n);
}
#endif

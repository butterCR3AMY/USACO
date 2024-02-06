#include <iostream>
using namespace std;

long long n, bact[200010], cnt = 0, diff, curX, sumi;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> bact[i];
    curX = bact[0];
    sumi = 0;
    cnt += abs(bact[0]);
    for (int i = 1; i < n; i++)
    {
        diff += -2*curX+sumi;
        sumi += -1*curX;
        bact[i] += diff;
        curX = bact[i];
        cnt += abs(curX);
    }
    cout << cnt;
}

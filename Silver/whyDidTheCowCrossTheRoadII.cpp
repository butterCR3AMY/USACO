#include <iostream>
using namespace std;

int n, k, b, x, arr[100001], l, r, broken, mini;
int main()
{
    ios::sync_with_stdio(false);cout.tie(0);cin.tie(0);
    freopen("maxcross.in", "r", stdin);
    freopen("maxcross.out", "w", stdout);
    cin >> n >> k >> b;
    for (int i = 0; i < b; i++)
    {
        cin >> x;
        //1 = broken, 0 = working
        arr[x-1] = 1;
    }
    //sliding window of width k
    l = 0;
    for (int i = 0; i < k; i++)
    {
        r = i;
        if (arr[i])
            broken++;
    }
    mini = (int)1e5;
    while (r < n-1)
    {
        mini = min(mini, broken);
        //l++ and r++
        broken += arr[r+1]-arr[l];
        l++;
        r++;
        mini = min(mini, broken);
    }
    cout << mini << '\n';
}

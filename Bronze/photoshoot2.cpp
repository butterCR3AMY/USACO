#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool done = true;
int n, cur, cnt = 0, is[100010], want[100010], posInWant[100010], maxi = 0;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> is[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> want[i];
        posInWant[want[i]] = i+1;
    }
    for (int i = 0; i < n; i++)
    {
        is[i] = posInWant[is[i]];
    }
    for (int i = 0; i < n; i++)
    {
        if (is[i] > maxi)
            maxi = is[i];
        else
            cnt ++;
    }
    cout << cnt << endl;
}

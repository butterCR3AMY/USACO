#include <iostream>
using namespace std;
#include <fstream>
#include <algorithm>
//#define THIS

#ifdef THIS
int cows[1000000];
int main()
{
    freopen ("cowqueue.in", "r", stdin);
    freopen ("cowqueue.out", "w", stdout);
    int n, pos, stayTime, curTime = 1;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> pos >> stayTime;
        cows[pos-1] += stayTime;
    }
    for (int i = 0; i < 1000000; i++)
    {
        if (cows[i] == 0)
            continue;
        curTime = max(i+1, curTime);
        curTime += cows[i];
    }
    cout << curTime;
}
#endif

//sol2
// #include <iostream>
// #include <algorithm>
// #define f first
// #define s second
// using namespace std;

// int cur, n;
// pair<int, int> arr[100];
// int main()
// {
//     freopen("cowqueue.in", "r", stdin);
//     freopen("cowqueue.out", "w", stdout);
//     cin >> n;
//     for (int i = 0; i < n; i++)
//         cin >> arr[i].f >> arr[i].s;
//     sort(arr, arr+n);
//     for (int i = 0; i < n; i++)
//     {
//         cur = max(cur, arr[i].f);
//         cur += arr[i].s;
//     }
//     cout << cur;
// }

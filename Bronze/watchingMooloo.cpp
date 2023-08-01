#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
//#define THIS

#ifdef THIS
int main()
{
    int n, k;
    cin >> n >> k;
    long long start, payed = 0, cur = 1+k;
    long long arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    start = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (cur + 1+k < arr[i]-start+1+k)
        {
            start = arr[i];
            payed += cur;
            cur = 1+k;
        }
        else
        {
            cur = arr[i]-start+1+k;
        }
    }
    payed += cur;
    cout << payed;
}
#endif

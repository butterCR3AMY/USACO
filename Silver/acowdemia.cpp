#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long n, k, l, h, pos, total, cur;
bool works;
vector<int> a;
int bs(int low, int hi)
{
    while (low < hi)
    {
        h = (low+hi+1)/2;
        //pos = last one to which was able to get it to mid
        pos = -1;
        //try mid as the h-index
        //in total can add at most k*l
        //to each can add at most k
        total = k*l;
        for (int i = 0; i < n; i++)
        {
            //do stuff
            if (a[i] < h)
            {
                cur = h-a[i];
                if (cur > total || cur > k)
                    break;
                total -= cur;
                pos = i;
            }
            else
                pos = i;
        }
        //pos+1 = one right after last one managed to set to h
        if (pos+1 >= h)
            low = h;
        else
            hi = h-1;
    }
    return low;
}
int main()
{
    cin >> n >> k >> l;
    for (int i = 0; i < n; i++)
    {
        cin >> cur;
        a.push_back(cur);
    }
    sort(a.rbegin(), a.rend());
    cout << bs(0, n);
}

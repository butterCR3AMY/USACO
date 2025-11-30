#include <iostream>
#include <algorithm>
#include <map>
#define f first
#define s second
#define ll long long
using namespace std;

ll n, prevX, prevY, ans, cur, sumBfor, sumAfter, numBfor, numAfter;
map<pair<ll, ll>, ll> res1, res2;
pair<ll, ll> arr[100010];
bool comp (pair<ll, ll> p1, pair<ll, ll> p2)
{
    return p1.s < p2.s || (p1.s == p2.s && p1.f < p2.f);
}
int main()
{
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].f >> arr[i].s;
//        arr[i].f += 10000;
//        arr[i].s += 10000;
    }
    //sort by X
    sort(arr, arr+n);
    prevX = -1;
    numBfor = 0;
    sumBfor = 0;
    for (int i = 0; i < n; i++) //go thru x
    {
        if (arr[i].f != prevX) //reached a new X
        {
            numBfor = 0;
            sumBfor = 0;
            prevX = arr[i].f;
        }
        res1[{arr[i].f, arr[i].s}] = numBfor*arr[i].s-sumBfor;
        numBfor++;
        sumBfor += arr[i].s;
    }
    prevX = -1;
    numBfor = 0;
    sumBfor = 0;
    for (int i = n-1; i >= 0; i--) //other way
    {
        if (arr[i].f != prevX) //reached a new X
        {
            numBfor = 0;
            sumBfor = 0;
            prevX = arr[i].f;
        }
        res1[{arr[i].f, arr[i].s}] += sumBfor-numBfor*arr[i].s;
        numBfor++;
        sumBfor += arr[i].s;
    }
    
    //sort by Y
    sort(arr, arr+n, comp);
    prevY = -1;
    numBfor = 0;
    sumBfor = 0;
    for (int i = 0; i < n; i++) //go thru y
    {
        if (arr[i].s != prevY) //reached a new y
        {
            numBfor = 0;
            sumBfor = 0;
            prevY = arr[i].s;
        }
        res2[{arr[i].f, arr[i].s}] = numBfor*arr[i].f-sumBfor;
        numBfor++;
        sumBfor += arr[i].f;
    }
    prevY = -1;
    numBfor = 0;
    sumBfor = 0;
    for (int i = n-1; i >= 0; i--) //other way
    {
        if (arr[i].s != prevY) //reached a new Y
        {
            numBfor = 0;
            sumBfor = 0;
            prevY = arr[i].s;
        }
        res2[{arr[i].f, arr[i].s}] += sumBfor-numBfor*arr[i].f;
        numBfor++;
        sumBfor += arr[i].f;
    }
    for (int i = 0; i < n; i++)
    {
        cur = (res1[{arr[i].f, arr[i].s}]%(ll)(1e9+7))*(res2[{arr[i].f, arr[i].s}]%(ll)(1e9+7));
        ans += cur;
        ans %= (ll)(1e9+7);
    }
    cout << ans;
}

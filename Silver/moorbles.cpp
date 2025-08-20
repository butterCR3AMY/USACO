#include <iostream>
#include <vector>
using namespace std;

long long t, n, m, k, small, spare, most, cur, minEven, minOdd, even, mini, odd, prefixSums[300010], guessEven[300010], guessOdd[300010], rem[300010], maxAfter[300010];
bool o, e, works;
vector<string> ans;
int main()
{
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> k;
        mini = 0;
        for (int i = 0; i < m; i++)
        {
            even = 0;
            odd = 0;
            minOdd = 1001;
            minEven = 1001;
            for (int j = 0; j < k; j++)
            {
                cin >> cur;
                if (cur%2 == 0)
                {
                    minEven = min(cur, minEven);
                    even = max(even, cur);
                }
                else
                {
                    minOdd = min(cur, minOdd);
                    odd = max(odd, cur);
                }
            }
            guessOdd[i] = even;
            guessEven[i] = odd;
            if (even == 0)
                guessOdd[i] = -1*minOdd;
            if (odd == 0)
                guessEven[i] = -1*minEven;
            mini += min(guessOdd[i], guessEven[i]);
            rem[i] = min(guessOdd[i], guessEven[i]);
            if (i == 0)
                prefixSums[i] = rem[i];
            else
                prefixSums[i] = prefixSums[i-1]+rem[i];
        }
        maxAfter[m] = prefixSums[m-1];
        for (int i = (int)m-1; i >= 0; i--)
        {
            if (i == m-1)
                maxAfter[i] = prefixSums[i];
            else
                maxAfter[i] = max(prefixSums[i], maxAfter[i+1]);
        }
        if (mini >= n)
        {
            cout << -1 << '\n';
            continue;
        }
        spare = n-mini;
        cur = n;
        works = true;
        ans.clear();
        for (int i = 0; i < m; i++)
        {
            //lose from cur every time
            //most possible to lose after
            most = maxAfter[i+1]-prefixSums[i];
            small = min(guessOdd[i], guessEven[i]);
            if (guessEven[i] <= guessOdd[i])
            {
                cur -= guessEven[i];
                e = true;
                o = false;
            }
            else if (cur-guessEven[i] > max(most, (long long)0))
            {
                cur -= guessEven[i];
                e = true;
                o = false;
            }
            else
            {
                cur -= guessOdd[i];
                o = true;
                e = false;
            }
            if (cur <= max(most, (long long)0))
                works = false;
            if (o)
            {
                if (i < m-1)
                    ans.push_back("Odd ");
                else
                    ans.push_back("Odd\n");
            }
            else
            {
                if (i < m-1)
                    ans.push_back("Even ");
                else
                    ans.push_back("Even\n");
            }
        }
        if (works)
        {
            for (int i = 0; i < ans.size(); i++)
                cout << ans[i];
        }
        else
            cout << -1 << '\n';
    }
}

#include <iostream>
using namespace std;

long long n, a, b, leftover, mini, multi, bfor, cnt, pow, cur;
int main()
{
    cin >> n;
    while (n--)
    {
        cin >> a >> b;
        mini = (long long)1e18;
        multi = 1;
        for (int curr = 0; multi <= b; curr++)
        {
            cnt = 0;
            bfor = b/multi;
            cur = a;
            while (cur > bfor)
            {
                if (cur%2 == 1)
                {
                    cur++;
                    cnt++;
                }
                cur/=2;
                cnt++;
            }
            cnt += bfor-cur;
            pow = 1;
            //get bfor to b by multiplying and adding
            while (bfor*2 <= b)
            {
                bfor *= 2;
                pow *= 2;
                cnt++;
            }
            leftover = b-bfor;
            while (leftover > 0)
            {
                cnt+=leftover/pow;
                leftover = leftover%pow;
                pow/=2;
            }
            mini = min(mini, cnt);
            multi *= 2;
        }
        cout << mini << '\n';
    }
}

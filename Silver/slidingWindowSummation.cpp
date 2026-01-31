#include <iostream>
#include <cstdlib>
using namespace std;

int t, n, m, k, cur, val, cnt, rn, mini, maxi, minDiff, miniNum, maxiNum;
string str;
int main()
{
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        cin >> str;
        m = (int)str.length();
        mini = 0;
        maxi = 0;
        miniNum = 0;
        maxiNum = 0;
        minDiff = 1;
        for (int i = 0; i < min(k, n-k); i++)
        {
            cur = 0; //num 1s
            cnt = 1; //total #
            val = 0;
            //find the mini and maxis by going thru;
            //assume i as 0 and then do cnt-cur to get alt ans
            
            //going from i's window to (i+1)'s window
            for (int j = i+k; j < n; j += k)
            {
                if (str[j-k+1] != str[j-k]) //val change
                    val = 1-val;
                cur += val;
                cnt++;
            }
            //either cur or cnt-cur
            if (i == 0)
                minDiff = abs(cur-(cnt-cur));
            else
                minDiff = min(minDiff, abs(cur-(cnt-cur)));
            if (cur < cnt-cur)
            {
                //use cur (0)
                mini += cur;
                //use cnt-cur (1);
                maxi += cnt-cur;
                maxiNum++;
            }
            else
            {
                //use cnt-cur (1)
                mini += cnt-cur;
                miniNum++;
                //use cur (0)
                maxi += cur;
                
            }
        }
        //two cases
        //fixed
        if (n-k+1 > k)
        {
            if (miniNum%2 == str[0]-'0')
                cout << mini << " ";
            else
                cout << mini+minDiff << " ";
            
            if (maxiNum%2 == str[0]-'0')
                cout << maxi << '\n';
            else
                cout << maxi-minDiff << '\n';
        }
        //flexible
        else
        {
            //n-k spots of the k taken
            //open = k-(n-k)
            if (minDiff == 0)
            {
                cout << mini << " " << maxi+k-(n-k) << '\n';
                continue;
            }
            if (miniNum%2 == str[0]-'0')
            {
                //open spots sum to 0 mod 2
                cout << mini << " ";
            }
            else
            {
                //open spots sum to 1 mod 2
                cout << mini+1 << " ";
            }
            
            if (maxiNum%2 == str[0]-'0')
            {
                //open spots sum to 0 mod 2
                if ((k-(n-k))%2 == 0)
                    cout << maxi+k-(n-k) << '\n';
                else
                    cout << maxi+k-(n-k)-1 << '\n';
            }
            else
            {
                //open spots sum to 1 mod 2
                if ((k-(n-k))%2 == 1)
                    cout << maxi+k-(n-k) << '\n';
                else
                    cout << maxi+k-(n-k)-1 << '\n';
            }
        }
    }
}

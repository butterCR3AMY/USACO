#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, b, cards[1010], cnt[1010], cur, curMax = 0, maxi = 0;
vector<int> boxes;

int main()
{
    // solve for each maximum number of cards inside of each box
    // if that value = k, then split the cards into sections
    // at most k and use % and division
    freopen("berries.in", "r", stdin);
    freopen("berries.out", "w", stdout);
    cin >> n >> b;
    cur = b;
    for (int i = 0; i < n; i++)
    {
        cin >> cards[i];
    }
    for (int k = 1; k <= 1000; k++)
    {
        cur = b;
        curMax = 0;
        boxes.clear();
        for (int i = 0; i < k; i++)
            cnt[i] = 0;
        for (int i = 0; i < n; i++)
        {
            cnt[k-1] += cards[i]/k;
            if (cards[i]%k)
                cnt[(cards[i]%k)-1] ++;
        }
        for (int i = k-1; i >= 0; i--)
        {
            if (cnt[i] == 0)
                continue;
            if (cur == 0)
            {
                break;
            }
            if (cur >= cnt[i])
            {
                for (int j = 0; j < cnt[i]; j++)
                {
                    boxes.push_back(i+1);
                }
                cur -= (cnt[i]);
            }
            else
            {
                for (int j = 0; j < cur; j++)
                {
                    boxes.push_back(i+1);
                }
                cur -= cur;
            }
        }
        sort(boxes.begin(), boxes.end());
        if(boxes.size() != b)
            continue;
        for (int i = 0; i < b/2; i++)
        {
            curMax += boxes[i];
        }
        if (curMax > maxi)
        {
            maxi = curMax;
        }
    }
    cout << maxi;
}

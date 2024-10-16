//Python Code
//inpu = open("circlecross.in", "r")
// circle = [0]*52
// circle = list(inpu.readline())
// inpu.close()
// alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
// pairs = 0
// for i in range(26):
//     for j in range(i+1, 26):
//         arri = []
//         arrj = []
//         for index in range(52):
//             if circle[index] == alphabet[i]:
//                 arri.append(index)
//             elif circle[index] == alphabet[j]:
//                 arrj.append(index)
//         if arri[0] < arrj[0] and arri[1] > arrj[0] and arri[1] < arrj[1]:
//             pairs += 1
//         elif arrj[0] < arri[0] and arrj[1] > arri[0] and arrj[1] < arri[1]:
//             pairs += 1
// ou = open("circlecross.out", "w")
// ou.write(str(pairs))
// ou.close

//cpp code
#include <iostream>
#include <algorithm>
#include <vector>
#define f first
#define s second
using namespace std;

int n = 52, cnt[26], ans, start;
string s;
int main()
{
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);
    cin >> s;
    for (int cur = 0; cur < 26; cur++)
    {
        start = 0;
        for (int i = 0; i < 26; i++)
            cnt[i] = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == (char)(cur+'A'))
                start = 1-start;
            if (start)
            {
                cnt[s[i]-'A']++;
            }
        }
        for (int i = 0; i < 26; i++)
            if (cnt[i] == 1 && i != cur)
                ans++;
    }
    cout << ans/2;
}

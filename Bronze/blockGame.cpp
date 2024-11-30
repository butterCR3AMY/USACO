#include <iostream>
#define f first
#define s second
using namespace std;

int n, cnt1[26], cnt2[26], ans[26];
pair<string, string> b[100];
int main()
{
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> b[i].f >> b[i].s;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            cnt1[j] = 0;
            cnt2[j] = 0;
        }
        for (int j = 0; j < b[i].f.length(); j++)
            cnt1[b[i].f[j]-'a']++;
        for (int j = 0; j < b[i].s.length(); j++)
            cnt2[b[i].s[j]-'a']++;
        for (int j = 0; j < 26; j++)
            ans[j] += max(cnt1[j], cnt2[j]);
    }
    for (int i = 0; i < 26; i++)
        cout << ans[i] << '\n';
}

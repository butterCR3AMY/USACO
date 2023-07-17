#include <iostream>
using namespace std;
//#define THIS

#ifdef THIS
int main()
{
    long long n, t, d, b, haybales = 0, pd = 0, pb = 0, eaten = 0;
    cin >> n >> t;
    for (int i = 0; i < n; i++)
    {
        cin >> d >> b;
        if (i == 0)
        {
            haybales += b;
            pb = b;
            pd = d;
            continue;
        }
        eaten += min(d-pd, haybales);
        haybales -= min(d-pd, haybales);
        pb = b;
        pd = d;
        haybales += b;
    }
    eaten += min(t-pd+1, haybales);
    haybales -= min(t-pd+1, haybales);
    cout << eaten << endl;
}
#endif

#include <iostream>
#include <bitset>
using namespace std;

int n, s, type[100010], val[100010], pos, speed, dir, cnt;
bitset<100000> broken;
int main()
{
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> type[i] >> val[i];
    speed = 1;
    dir = 1;
    pos = s-1;
    while(pos < n && pos >= 0 && cnt <= 1e6)
    {
        if (speed >= val[pos] && type[pos] == 1)
            broken[pos] = 1;
        else
        {
            if (type[pos] == 0)
            {
                dir *= -1;
                speed += val[pos];
            }
        }
        cnt++;
        pos += speed*dir;
    }
    cout << (broken.count());
}

#include <iostream>
using namespace std;

int main()
{
    int n;
    while ((cin >> n))
    {
        int cnt = 1;
        int ret = 1;
        while (1)
        {
            if(!(cnt % n))
            {
                cout << ret << '\n';
                break;
            }
            else
            {
                cnt = (cnt * 10) + 1;
                cnt %= n;
                ret++;
            }
        }
    }
    
    return 0;
}
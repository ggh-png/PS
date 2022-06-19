#include <iostream>

using namespace std;

int main()
{
    int ans = 0;
    for(int i=0; i < 5; i++)
    {
        int tmp;
        cin >> tmp;
        tmp *= tmp;
        ans += tmp;
    }
    ans %= 10;
    cout << ans << endl;
    return 0;
}
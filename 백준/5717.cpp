#include <iostream>
using namespace std;

int main()
{
    int a, b;
    while(1)
    {
        cin >> a >> b;
        if(a == 0 && b == 0)
            break;
        int ans = a + b;

        cout << ans << endl;
    }
    return 0;
}
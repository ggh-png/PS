#include <iostream>

using namespace std;

int num;
long long ans = 1;

int main()
{
    cin >> num;
    for(int i=1; i <= num; i++)
        ans *= i;
    cout << ans << endl;
    return 0;
}

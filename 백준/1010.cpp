#include <iostream>

using namespace std;


int main()
{
    int num;
    cin >> num;
    for(int i=0; i < num; i++)
    {
        int n, r;
        cin >> r >> n;
        long long ans = 1;
        int p = 1;
        for(int i=n; i > (n-r); i--)
        {
            ans *= i;
            ans /= p++;
        }
        cout << ans << endl;
    }
    return 0;
}
#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    // 4 6
    // 
    int ans = 0;
    if(n != 1)
        ans = n - 1 + (n * (m -1)); 
    else
        ans = m - 1 + (m * (n - 1));
    cout << ans << endl;
    return 0;
}
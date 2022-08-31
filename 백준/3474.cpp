#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int num;
    cin >> num;

    for(int i=0; i < num; i++)
    {
        int n;
        cin >> n;
        int ret2 = 0;
        int ret5 = 0;
        for(int j=2; j <= n; j*=2)
            ret2 += n / j;
        for(int j=5; j <= n; j*=5)
            ret5 += n / j;

        cout << min(ret2, ret5) << '\n';
    }
    return 0;
}
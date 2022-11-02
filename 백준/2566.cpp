#include <iostream>
using namespace std;

int main()
{
    int n=1, m=1;
    int ans = 0;
    for(int i=1; i <= 9; i++)
        for(int j=1; j <= 9; j++)
        {
            int tmp;
            cin >> tmp;
            if(tmp > ans)
            {
                ans = tmp;
                n = i;
                m = j;
            }
        }
    cout << ans << endl;
    cout << n << " " << m << endl;
    return 0;
}
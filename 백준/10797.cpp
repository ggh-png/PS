#include <iostream>
using namespace std;


int main()
{
    int num;
    cin >> num;
    int ans = 0;
    for(int i=0; i < 5; i++)
    {
        int tmp;
        cin >> tmp;
        if(tmp == num)
            ans++;
    }
    cout << ans << endl;
    return 0;
}
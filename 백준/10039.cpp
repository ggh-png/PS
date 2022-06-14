#include <iostream>
using namespace std;

int main()
{
    int ans=0;
    for(int i=0; i < 5; i++)
    {
        int temp;
        cin >> temp;
        if(temp < 40)
            temp = 40;
        ans += temp;
    }
    cout << ans / 5 << endl;
    return 0;
}
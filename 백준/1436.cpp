#include <iostream>
using namespace std;


int main()
{
    int num;
    cin >> num;
    int cnt = 666;
    while(num)
    {
        if(to_string(cnt).find("666") != string::npos)
            num--;
    
        cnt++;
    }
    cout << cnt-1 << endl;
    return 0;
}
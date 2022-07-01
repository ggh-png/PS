#include <iostream>

using namespace std;

int main()
{
    string str;
    cin >> str;

    int ans  = 10;
    for(int i=1; i < str.size(); i++)
    {
        if(str[i-1] == str[i])
            ans += 5;
        else
            ans += 10; 
    }
    cout << ans << endl;
    return 0;
}
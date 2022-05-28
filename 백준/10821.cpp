#include <iostream>
#include <string>

using namespace std;

int main()
{
    int ans = 1;
    string str;
    cin >> str;
    for(auto &el : str)
        if(el == ',')
            ans++;
    cout << ans;
    return 0;
}
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;

    int cnt = 0;
    string ans = "";
    for(auto &el : str)
    {
        if(ans.size() == 10)
        {
            cout << ans << endl;
            ans = el;
        }
        else
            ans += el;
    }
    cout << ans << endl;
    return 0;
}
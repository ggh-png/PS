#include <iostream>
using namespace std;

int main()
{
    string s = "aeiou";
    string str;
    int ans = 0;
    cin >> str;

    for(auto &el : str)
        for(auto &e : s)
            if(el == e)
                ans++;
    cout << ans << endl;

    return 0;
}
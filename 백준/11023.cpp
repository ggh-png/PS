#include <iostream>

using namespace std;

int main()
{
    string str;
    int ans = 0;
    
    string tmp;
    getline(cin, str);
    for(auto &el : str)
        if(el == ' ')
        {
            ans += stoi(tmp);
            tmp = "";
        }
        else
            tmp += el;
    ans += stoi(tmp);
    cout << ans << endl;
}
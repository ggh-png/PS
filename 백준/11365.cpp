#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    string str = "";
    vector<string> ans;
    while(1)
    {
        getline(cin, str);
        if(str == "END")
            break;
        else
        {
            reverse(str.begin(), str.end());
            ans.push_back(str);
        }
    }
    for(auto &el : ans)
        cout << el << '\n';
    return 0;
}
#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    string  str1, str2;
    
    while(cin >> str1 >> str2)
    {
        string ans = "Yes";
        for(auto &el : str1)
        {
            if(str2.find(el) != string::npos)
            {
                int idx = str2.find(el);
                str2.erase(0, idx + 1);
            }
            else
                ans = "No";
        }
        cout << ans << '\n';
    }
    return 0;
}
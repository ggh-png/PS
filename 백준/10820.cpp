#include <iostream>
#include <string>
using namespace std;


int main()
{
    string str;
    while(getline(cin, str))
    {
        int ans[] = {0, 0, 0, 0};
        for(auto &el : str)
        {
            if(el >= 'a' && el <= 'z')
                ans[0]++;
            else if(el >= 'A' && el <= 'Z')
                ans[1]++;
            else if(el >= '0' && el <= '9')
                ans[2]++;
            else if(el == ' ')
                ans[3]++;
        }
        cout << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3] << '\n';
    }
    return 0;
}
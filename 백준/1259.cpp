#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string str;
    while(1)
    {
        cin >> str;
        if(str != "0")
        {
            string tmp = str;
            reverse(str.begin(), str.end());
            string answer = str == tmp ? "yes" : "no";
            cout << answer << endl;
        }
        else
            break;
    }
    return 0;
}
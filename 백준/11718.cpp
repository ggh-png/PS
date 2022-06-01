#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str = "s";
    while(str != "")
    {
        getline(cin, str);
        cout << str << '\n';
    }
    return 0;
}
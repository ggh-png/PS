#include <iostream>
using namespace std;

int main()
{
    string str;
    cin >> str;
    for(auto &el : str)
    {
        if(el >= 'a' && el <= 'z')
            el -= 32;
        else
            el += 32;
    }
    cout << str << endl;
}
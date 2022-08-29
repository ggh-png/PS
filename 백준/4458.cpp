#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int num;
    cin >> num;
    cin.ignore();
    for(int i=0; i <= num; i++)
    {
        string str;
        
        getline(cin, str);
        if(str[0] >= 'a' && str[0] <= 'z')
            str[0] = str[0] - 32;
        cout << str << endl;
    }
    return 0;
}
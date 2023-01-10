#include <iostream>

using namespace std;

int main()
{
    string str;
    cin >> str;
    char c = str[0];
    int cnt = 1;
    for(int i=1; i < str.size(); i++)
    {
        if(str[i-1] != str[i])
            break;
        else
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}
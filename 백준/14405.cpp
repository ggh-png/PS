#include <iostream>

using namespace std;

int main()
{
    string pi="pi", ka = "ka", chu = "chu";
    string str;
    cin >> str;
    string ans = "YES";
    
    for(int i=0; i < str.size(); i++)
    {
        if(str[i] == 'p' && str[i+1] == 'i')
            i++;
        else if(str[i] == 'k' && str[i+1] == 'a')
            i++;
        else if(str[i] == 'c' && str[i+1] == 'h' && str[i+2] == 'u')
            i+=2;
        else
            ans = "NO";
    }
    cout << ans << endl;

    return 0;
}
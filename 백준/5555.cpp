#include <iostream>
#include <string>

using namespace std;


int main()
{
    string str;
    cin >> str;
    int num;
    cin >> num;
    int ans = 0;
    for(int i=0; i < num; i++)
    {
        string tmp;
        cin >> tmp;
        tmp += tmp;
        if(tmp.find(str) != std::string::npos)
            ans++;
    }
    cout << ans << endl;
}
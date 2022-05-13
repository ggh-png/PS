#include <iostream>
#include <string>
#include <vector>

using namespace std;
// 소문자 97 ~ 122
int main()
{
    string str;
    vector<int> abc(26, -1);
    cin >> str;
    
    for(int i=0; i < str.size(); i++)
        if(abc[str[i] - 97] == -1)
            abc[str[i] - 97] = i;
    for(auto &el : abc)
        cout << el << " ";
    cout << '\n';
    
    return 0;
}
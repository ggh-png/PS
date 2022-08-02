#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    int num;
    cin >> num;
    int ans=0;
    string str;
    for(int i=0; i < num; i++)
    {
        cin >> str;
        stack<char> s;
        for(int j=0; j < str.size(); j++)
        {
            if(s.empty())
                s.push(str[j]);
            else
            {
                if(s.top() != str[j])
                    s.push(str[j]);
                else
                    s.pop();
            }
        }
        if(s.empty())
            ans++;
    }
    cout << ans << endl;
    return 0;
}
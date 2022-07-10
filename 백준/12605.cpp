#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int num;
    cin >> num;
    stack<string> s;
    string str[num];

    cin.ignore();

    for(int i=0; i < num; i++)
        getline(cin, str[i]);

    for(int i=1; i <= num; i++)
    {
        string tmp = "";
        
        for(auto &el : str[i-1])
        {
            if(el == ' ')
            {
                s.push(tmp);
                tmp = "";
            }
            else
                tmp += el;   
        }
        if(tmp.size() != 0)
            s.push(tmp);
        cout << "Case #" << i << ": ";
        while (!s.empty())
        {
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    }
    return 0;
}
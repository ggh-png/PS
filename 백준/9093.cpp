#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int num;
    cin >> num;
    cin.ignore();
    vector<string> str_v(num);
    for(int i=0; i < num; i++)
        getline(cin, str_v[i]);

    for(int i=0; i < num; i++)
    {
        string str = str_v[i];
        vector<string> v;
        string tmp = "";
        for(int i=0; i <= str.size(); i++)
        {
            if(i == str.size())
                v.push_back(tmp);

            if(str[i] == ' ')
            {
                v.push_back(tmp);
                tmp.clear();
            }
            else
                tmp += str[i];
        }

        while(!v.empty())
        {
            reverse(v.front().begin(), v.front().end());
            cout << v.front() << " ";
            v.erase(v.begin());
        }
        cout << '\n';
    }
    return 0;
}
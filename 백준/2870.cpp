#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool compare(string a, string b)
{
    if(a.size() == b.size())
        return a < b;
    return a.size() < b.size();
}

int main()
{
    int num;
    cin >> num;
    // 앞자리에 0이오면 무시한다.
    vector<string> v;
    for(int i=0; i < num; i++)
    {
        string str;
        cin >> str;
        string tmp = "";
        for(int j=0; j < str.size(); j++)
        {
            if(str[j] >= '0' && str[j] <= '9')
                tmp += str[j];
            if(str[j] >= 'a' && str[j] <= 'z' && tmp.size())
            {
                while(tmp[0] == '0' && tmp.size() > 1)
                {
                    tmp.erase(tmp.begin());
                }
                v.push_back(tmp);
                tmp = "";
            }
            
            if(j == str.size()-1 && tmp.size())
            {
                while(tmp[0] == '0' && tmp.size() > 1)
                {
                    tmp.erase(tmp.begin());
                }
                v.push_back(tmp);
                tmp = "";
        
            }
        }
    }

    sort(v.begin(), v.end(), compare);

    for(auto &el : v)
        cout << el << '\n';
    
    return 0;
}
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    int n;
    cin >> n;
    map<string, int> mp;
    for(int i=0; i < n; i++)
    {
        string str;
        cin >> str;
        bool flag = 0;
        string tmp = "";
        for(int j=0; j < str.size(); j++)
        {
            if(flag)
                tmp += str[j];
            if(str[j] == '.')
                flag = 1;
        }
        mp[tmp] += 1;
    }

    vector<pair<string, int>> v(mp.begin(), mp.end());

    sort(v.begin(), v.end(), 
    [](pair<string, int>& a, pair<string, int>& b)
    {
        return a.first < b.first;
    });

    for(auto &el : v)
        cout << el.first << " " << el.second << '\n';


    return 0;
}

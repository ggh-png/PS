#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int n, m;
map<string, int> mp;
vector<pair<pair<string, int>, int>> v;

bool compare(pair<pair<string, int>, int> a, pair<pair<string, int>, int> b)
{
    if(a.first.second == b.first.second)
    {
        if(a.first.first.size() == b.first.first.size())
            return a.first.first < b.first.first;
        return a.first.first.size() > b.first.first.size();
    }

    return a.first.second > b.first.second;
}


int main()
{
    cin >> n >> m;
    for(int i=0; i < n; i++)
    {
        string str;
        cin >> str;
        if(str.size() >= m)
            mp[str] += 1;
    }
    int cnt = 0;
    for(auto &el : mp)
    {
        cnt++;
        string fir = el.first;
        int sec = el.second;
        v.push_back({{fir, sec}, cnt});
    }
    sort(v.begin(), v.end(), compare);
 
    for(auto &el : v)
        cout << el.first.first << '\n';
    return 0;
}
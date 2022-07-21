#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{   
    int n, m;
    cin >> n >> m;
    map<string, int> mapSet;

    for(int i=0; i < n; i++)
    {
        string str;
        cin >> str;
        mapSet[str] += 1;
    }
    int cnt = 0;

    vector<string> ans;
    for(int i=0; i < m; i++)
    {
        string str;
        cin >> str;
        if(mapSet[str] == 1)
        {
            cnt++;
            ans.push_back(str);
        }
    }
    sort(ans.begin(), ans.end());
    cout << cnt << '\n';
    for(auto &el : ans)
        cout << el << '\n';

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<pair<int, int>, int>> v;
vector<pair<pair<int, int>, int>> ans;
int arr[104];
bool compare(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
    return a.second > b.second;
}

int main()
{
    int num;
    cin >> num;
    
    for(int i=0; i < num; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({{a, b}, c});
    }
    sort(v.begin(), v.end(), compare);
    for(int i=0; i < num; i++)
    {
        arr[v[i].first.first]++;
        if(arr[v[i].first.first] <= 2)
            ans.push_back(v[i]);
    }
    if(ans.size() < 3)
    {
        cout << ans[0].first.first << " " << ans[0].first.second << endl;
        cout << ans[1].first.first << " " << ans[1].first.second << endl;  
    }
    else
    {
        cout << ans[0].first.first << " " << ans[0].first.second << endl;
        cout << ans[1].first.first << " " << ans[1].first.second << endl;
        cout << ans[2].first.first << " " << ans[2].first.second << endl;
    }
}
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(pair<int, int> a,
             pair <int, int> b)
{
    return a.first < b.first;
}
int main()
{
    vector<pair<int, int>> v;

    for(int i=1; i <= 9; i++)
    {
        int temp; 
        cin >> temp;
        v.push_back(pair<int, int>(temp, i));
    }
    sort(v.begin(), v.end(), compare);
    cout << v.back().first << " " << v.back().second;
    return 0;
}
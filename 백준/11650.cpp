#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool compair(pair<int,int> a,
             pair<int,int> b)
{
    if(a.first == b.first)
        return a.second < b.second;
    return a.first < b.first; 
}

int main()
{
    int num;
    int x, y;
    vector<pair<int,int>> xy_list;
    scanf("%d", &num);
    for(int i=0; i < num; i++)
    {
        scanf("%d%d", &x, &y);
        xy_list.push_back(pair<int, int>(x, y));
    }
    sort(xy_list.begin(), xy_list.end(), compair);
    for(int i=0; i < xy_list.size(); i++)
        printf("%d %d\n", xy_list[i].first, xy_list[i].second);
}
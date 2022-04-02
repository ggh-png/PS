#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool compare(pair<int, pair<int, string>> a,
             pair<int, pair<int, string>> b)
{
    if(a.second.first == b.second.first)
        return a.first < b.first;
    return a.second.first < b.second.first; 
}

int main()
{
    int num;
    int old;
    char name[101];
    vector<pair<int, pair<int, string>>> m_list;
    scanf("%d", &num);
    for(int i=0; i < num; i++)
    {
        scanf("%d%s",&old ,name);
        m_list.push_back(pair<int, pair<int, string>>(i, make_pair(old, name)));
    }
    sort(m_list.begin(), m_list.end(), compare);
    for(int i=0; i < m_list.size(); i++)
        printf("%d %s\n", m_list[i].second.first, m_list[i].second.second.c_str());
}
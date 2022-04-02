#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool compare(string a,
             string b)
{
    if(a.size() == b.size())
        return a < b;
    return a.size() < b.size(); 
}


int main()
{
    int num;
    string str;
    vector<string> st_list;
    scanf("%d", &num);
    for(int i=0; i < num; i++)
    {
        cin >> str;
        st_list.push_back(str);
    }
    sort(st_list.begin(), st_list.end(), compare);
    st_list.erase(unique(st_list.begin(), st_list.end()), st_list.end());
    for(int i=0; i < st_list.size(); i++)
        cout << st_list[i] << endl;
}
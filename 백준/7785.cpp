#include <iostream>
#include <map>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int num;
    cin >> num;
    map<string, bool, greater<>> map;
    for(int i=0; i < num; i++)
    {
        string name;
        string state;
        cin >> name >> state;
        if(state == "enter")
            map[name] = 1;
        else
            map[name] = 0;
    }
    for(auto &el : map)
        if(el.second == 1)
            cout << el.first << '\n';

    return 0;
}
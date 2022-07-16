#include <iostream>
#include <map>

using namespace std;

int main()
{
    int num;
    cin >> num;

    map<string, int> map;
    
    for(int i=0; i < num; i++)
    {
        string str;
        cin >> str;
        map[str] += 1;
    }
    int max = 0;
    string ans;
    for(auto &el : map)
    {
        if(el.second > max)
        {
            max = el.second;
            ans = el.first;
        }
    }
    cout << ans << endl;
    return 0;
}
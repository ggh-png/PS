#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class menber
{
public:
    int coin;
    string name;
};

bool compare(menber a, menber b)
{
    return a.coin > b.coin;
}

int main()
{
    int num;
    cin >> num;
    for(int i=0; i < num; i++)
    {
        int n;
        cin >> n;
        vector<menber> v;
        for(int j=0; j < n; j++)
        {
            menber m;
            cin >> m.coin >> m.name;
            v.push_back(m);
        }
        sort(v.begin(), v.end(), compare);
        cout << v.front().name << endl;
    }
    return 0;
}
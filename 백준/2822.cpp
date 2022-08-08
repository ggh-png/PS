#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class num
{
public:
    int num1, num2;
};

bool compare1(num a, num b)
{
    return a.num1 > b.num1;
}
bool compare2(num a, num b)
{
    return a.num2 < b.num2;
}

int main()
{
    vector<num> v(8);

    for(int i=0; i < 8; i++)
    {
        num tmp;
        cin >> v[i].num1;
        v[i].num2 = i+1;
    }
    sort(v.begin(), v.end(), compare1);
    v.erase(v.begin() + 5, v.end());
    sort(v.begin(), v.end(), compare2);

    int ans = 0;
    for(auto &el : v)
        ans += el.num1;

    cout << ans << endl;

    for(auto &el : v)
        cout << el.num2 << " ";
    cout << endl;
    return 0;
}
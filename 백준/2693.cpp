#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int num;
    vector<int> v(10);
    cin >> num;
    for(int i=0; i < num; i++)
    {
        for(int j=0; j < 10; j++)
            cin >> v[j];
        sort(v.rbegin(), v.rend());
        cout << v[2] << '\n';
    }
    return 0;

}
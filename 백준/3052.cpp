#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v(10);
    for(int i=0; i < 10; i++)
    {
        int tmp;
        cin >> tmp;
        v[i] = tmp % 42;
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    cout << v.size();

    return 0;
}
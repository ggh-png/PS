#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int num;
    cin >> num;
    vector<int> v = {0, 1, 1};

    for(int i=3; i <= num; i++)
        v.push_back(v[i-1] + v[i-2]);
    if(num > 2)
        cout << v.back();
    else
        cout << v[num];
    return 0;
}
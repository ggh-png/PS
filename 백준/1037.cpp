#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main()
{
    int num;
    cin >> num;
    vector<int> v(num);

    for(int i=0; i < num; i++)
        cin >> v[i];

    sort(v.begin(), v.end());
    cout << v.front() * v.back();
    
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int num;
    cin >> num;
    vector<int> v(num);
    for(int i=0; i < num; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    for(auto &el : v)
        cout << el << '\n';
    return 0;
}

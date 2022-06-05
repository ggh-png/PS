#include <iostream>
#include <algorithm>
#include <vector>

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
    
    sort(v.rbegin(), v.rend());
    for(auto &el : v)
        cout << el << '\n';
    
    return 0;
}
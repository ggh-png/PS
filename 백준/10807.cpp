#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int num;
    cin >> num;
    vector<int> v(num);
    for(int i=0; i < num; i++)
        cin >> v[i];
    int N;
    cin >> N;
    int ans = 0;
    for(auto &el : v)
        if(el == N)
            ans++;
    cout << ans;
    return 0;
}
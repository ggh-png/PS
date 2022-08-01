#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    ll max = -100 * 100000;
    ll psum[100001];

    for(int i=1; i <= n; i++)
    {
        int temp; 
        cin >> temp;
        psum[i] = psum[i-1] + temp;
    }
    
    for(int i=m; i <= n; i++)
        max = max > psum[i] - psum[i-m] ? max : psum[i] - psum[i-m];
    cout << max << '\n';
    return 0;
}
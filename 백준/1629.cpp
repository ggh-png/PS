#include <iostream>
using namespace std;

typedef long long ll;

ll go(ll &a, ll b, ll &c)
{
    if(b == 1) 
        return a % c;
    ll _c = go(a, b / 2, c);
    _c = (_c * _c) % c;
    if(b % 2)
        _c = (_c * a) % c;
    return _c;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll a, b, c;
    cin >> a >> b >> c;
    cout << go(a, b, c) << "\n";    
    return 0;
}
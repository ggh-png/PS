#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<bool> arr(1000001);
    arr[0] = true;
    arr[1] = true;

    for(int i=2; i <= sqrt(1000001); i++)
        if(!arr[i])
            for(int j=i+i; j <= 1000001; j+=i)
                arr[j] = true;

    for(int i=n; i <= m; i++)
        if(!arr[i])
            cout << i << '\n';

    return 0;
}
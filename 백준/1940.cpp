#include <iostream>

using namespace std;

int main()
{
    int n, m;
    
    cin >> n >> m;
    int arr[n];
    
    for(int i=0; i < n; i++)
        cin >> arr[i];
    int ans = 0;


    for(int i=0; i < n; i++)
        for(int j=i+1; j < n; j++)
            if(arr[i] + arr[j] == m)
                ans++;
    cout << ans << endl;
    return 0;
}
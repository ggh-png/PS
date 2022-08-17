#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int m, n;
    cin >> n >> m;
    int arr[n];
    for(int i=0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    cout << arr[n-(m-1)-1];
    return 0;
}
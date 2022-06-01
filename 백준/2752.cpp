#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int arr[3];
    for(int i=0; i < 3; i++)
        cin >> arr[i];
    sort(arr, arr+3);
    for(auto &el : arr)
        cout << el << " ";
    return 0;
}
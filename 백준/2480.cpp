#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main()
{
    vector<int> arr(3);
    cin >> arr[0] >> arr[1] >> arr[2];
    sort(arr.begin(), arr.end());
    if(arr[2] == arr[1] && arr[1] == arr[0])
        cout << arr[0] * 1000 + 10000;
    else if(arr[0] == arr[1] && arr[1] != arr[2])
        cout << arr[0] * 100 + 1000;
    else if(arr[0] != arr[1] && arr[1] == arr[2])
        cout << arr[1] * 100 + 1000;
    else if(arr[0] != arr[1] && arr[1] != arr[2])
        cout << arr[2] * 100;
        

    return 0;
}
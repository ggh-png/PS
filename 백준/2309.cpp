#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> arr(9);
    int sum = 0;

    for(int i=0; i < 9; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    sort(arr.begin(), arr.end());
    sum -= 100;
    bool flag = true;
    for(int i=0; i < 9; i++)
    {
        if(flag)
            for(int j=i+1; j < 9; j++)
            {
                if(sum == arr[i] + arr[j])
                {
                    arr[i] = 0;
                    arr[j] = 0;
                    flag = false;
                    break;
                }
            }
    }
    for(auto &el : arr)
    {
        if(el != 0)
            cout << el << endl;
    }
    return 0;
}
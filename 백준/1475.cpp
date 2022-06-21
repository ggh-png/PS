#include <iostream>

using namespace std;

int main()
{
    string str;
    cin >> str;
    int arr[10] = {0};
    for(auto &el : str)
    {
        if(el == '6' || el == '9')
        {
            if(arr[6] <= arr[9])
                arr[6]++;
            else
                arr[9]++;
        }
        else
            arr[el-48]++;
    }

        
    int answer = 0;
    for(auto &el : arr)
        if(el > answer)
            answer = el;

    cout << answer << endl;
    return 0;
}
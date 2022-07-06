#include <iostream>
#include <algorithm>

using namespace std;


int main()
{
    string str;
    cin >> str;
    int arr_size = str.size();
    string arr[arr_size];
    for(int i=0; i < arr_size; i++)
    {    
        arr[i] = str;
        str.erase(str.begin());
    }
    sort(arr, arr + arr_size);
    for(auto &el : arr)
        cout << el << endl;
    return 0;
}
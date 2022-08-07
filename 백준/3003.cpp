#include <iostream>
using namespace std;

int main()
{
    int arr[6] = {1,1,2,2,2,8};
    for(int i=0; i < 6; i++)
    {
        int tmp;
        cin >> tmp;
        arr[i] -= tmp;
    }
    for(auto &el : arr)
        cout << el << " ";
    cout << '\n';
    return 0;
}
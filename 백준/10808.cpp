#include <iostream>

using namespace std;
 
int main()
{
    int arr[26] = {0};
    string str;
    cin >> str;
    for(auto &el : str)
        arr[el - 'a']++;
    
    for(auto &el : arr)
        cout << el << " ";
    cout << endl;
    return 0;
}
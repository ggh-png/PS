#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int num; 
    cin >> num; 
    vector<int> arr(num);
    for(int i=0; i < num; i++)
        cin >> arr[i];
    // 오름차순 정렬
    sort(arr.begin(), arr.end()); 
    // 중복제거    
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    for(auto &el : arr)
        cout << el << " ";
    cout << '\n';
    return 0;
}
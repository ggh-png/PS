#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void solution(vector<int> arr) 
{
    sort(arr.begin(), arr.end());    
    for(auto el : arr)
        cout << el << '\n';
}

int main()
{
    int N;
    cin >> N; 
    vector<int> arr(N);
    for(int i=0; i < N; i++)
        cin >> arr[i];


    solution(arr);

    return 0;
}

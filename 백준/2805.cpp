#include <iostream>
#include <vector>
using namespace std;

// 설명 blog
// ggh-png.github.io 

int BinarySearch(vector<long long> &arr, int &N, const long long &begin, const long long &end)
{
    long long m = (begin + end) / 2;
    if(begin == end)
        return m;
    long long sum = 0;
    for(auto &el : arr)
        if(el >= m)
            sum += el - m;
    if(sum >= N)
        return BinarySearch(arr, N, m, end+1);   
    else
        return BinarySearch(arr, N, begin, m-1);
}

int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<long long> arr(n);
    // 나무 입력 받기 
    long long max = 0;
    long long min;
    for(int i=0; i < n; i++)
    {
        cin >> arr[i];
        if(arr[i] > max)
            max = arr[i];
    }
    min = max - m;
    cout << BinarySearch(arr, m, min, max) << endl;
    return 0;
}
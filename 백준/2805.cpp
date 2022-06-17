#include <iostream>
#include <vector>
using namespace std;
// 필요로한 나무를 얻기위한 최소한의 나무길이를 구해라. 

long long BinarySearch(vector<long long> &arr, long long &N, const long long &begin, const long long &end)
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
    long long n, m;
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
    // begin : 0 end :n max
    cout << BinarySearch(arr, m, min, max) << endl;
 
    return 0;
}
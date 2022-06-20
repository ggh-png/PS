#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int BinarySearch(vector<long long> &arr,long long &k, const long long &begin, const long long &end)
{
    long long m = (begin + end) / 2;
    if(begin >= end)
        return m;
    long long sum = 0;
    for(auto &el : arr)
    {
        if(el < m)
            sum += el;
        else
            sum += m;
    }
    if(sum <= k)
        return BinarySearch(arr, k, m, end + 1);
    else
        return BinarySearch(arr, k, begin, m - 1);
}



int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int num;
    cin >> num;
    vector<long long> arr(num);
    long long sum = 0;

    for(int i=0; i < num; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    long long m;
    cin >> m;
    sort(arr.begin(), arr.end());

    //120 110 140 150
    if(sum <= m)
        cout << arr.back();
    else
        cout << BinarySearch(arr, m, 1, arr.back()) << endl;
    return 0;
}
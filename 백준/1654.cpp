#include <iostream>
#include <vector>
using namespace std;


int BinarySearch(vector<long long> &v, int N, long long begin, long long end)
{
    long long m = (begin + end) / 2;

    if(begin >= end) return m;
    int cnt = 0;
    for(int j=0; j < v.size(); j++)
    {
        cnt += v[j] / m;
        if(cnt == N)
            return BinarySearch(v, N, m, end+1);
    }    
    if(cnt == N) return BinarySearch(v, N, m, end+1);
    else if(cnt < N) return BinarySearch(v, N, begin, m-1);
    else return BinarySearch(v, N, m, end+1);
}

int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
  
    long long K, N;
    cin >> K >> N;
    vector<long long> v(K);
    long long sum=0;

    for(int i=0; i < K; i++)
    {
        cin >> v[i];
        sum += v[i];
    }
    sum /= N;
    // 모두 더한 후 최대공약수를 구한다. 
    cout << BinarySearch(v, N, 1, sum) << '\n';
    return 0;
}
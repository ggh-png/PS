#include <iostream>

using namespace std;

long long BinarySearch(long long begin, long long end, long long x, long long y, long long k)
{
    long long m = (begin + end) / 2;
    if(begin >= end)
        return m;
    
    long long z = (y + m) * 100 / (x + m);
    if(z > k)
        return BinarySearch(begin, m - 1, x, y, k);
    else
        return BinarySearch(m, end + 1, x, y, k);
}


int main()
{
    long long x, y;
    cin >> x >> y;
    long long z = y * 100 / x;
    if(z >= 99)
        cout << -1 << endl;
    else
        cout << BinarySearch(0, 1000000000, x, y, z) + 1 << endl;

    return 0;
}
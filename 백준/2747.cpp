#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // 피보나치 구현 
    vector<int> fibo(46);
    fibo[0] = 0;
    fibo[1] = 1;
    fibo[2] = 1;
    // n = (n-1) + (n-2)
    for(int i=3; i < 47; i++)
        fibo[i] = fibo[i-1] + fibo[i-2];
    
    int num;
    cin >> num;
    cout << fibo[num];
    return 0;
}
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
// 10,000의 자연수  
int main()
{
    int a, b;
    cin >> a >> b;
    
    vector<bool> arr(10001, 0);
    arr[0] = true;
    arr[1] = true;

    // 소수 리스트 생성 
    for(int i=2; i <= sqrt(10001); i++)
        if(!arr[i])
            for(int j=i+i; j <= 10001; j+=i)
                arr[j] = true;
    
    vector<int> v;
    for(int i=a; i <= b; i++)
        if(!arr[i])
            v.push_back(i);

    int sum = 0;
    if(!v.empty())
    {
        for(auto &el : v)
            sum += el;
        cout << sum << endl << v.front();
    }
    else
        cout << "-1";

    
    return 0;
}
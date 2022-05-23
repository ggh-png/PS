#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int num;
    // 0을 입력받을 때 까지 
    // num 123,456
    vector<bool> arr(123456*2+1, 0);
    arr[0] = true;
    arr[1] = true;
    // 소수 추출 
    for(int i=0; i <= sqrt(123456*2+1); i++)
        if(!arr[i])
            for(int j=i+i; j <= 123456*2+1; j+=i)
                arr[j] = true;
                
    while(1)
    {
        cin >> num;
        if(num)
        {
            int cnt=0;
            // 범위내 소수가 존재하면 cnt++
            for(int i=num+1; i <= 2*num; i++)
                if(!arr[i])
                    cnt++;
            cout << cnt << '\n';
        }  
        else
            break;   
    }

    return 0;
}
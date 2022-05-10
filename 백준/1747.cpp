#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


int main()
{
    int num;
    int answer;
    cin >> num;
    vector<bool> arr(10000001, 0);
    arr[1] = true;
    for(int i=2; i <= sqrt(10000000); i++)
    {
        if(!arr[i])
            for(int j=i+i; j <= 10000000; j+=i)
                arr[j] = true;
    } 
    for(int i=0; i < 10000001; i++)
    {
        if(!arr[i] && i >= num)// 소수 이면서
        {   // 문자열로 변환 후 revese시에도 같은수면 
            string temp = to_string(i);
            reverse(temp.begin(), temp.end());
            if(temp == to_string(i))
            {
                answer = i;
                break;
            }
        }
    }
    cout << answer << endl;
    return 0;
}
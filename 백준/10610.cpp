#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

// 입력받은 숫자를 조합하여 30의 배수가 되는 가장 큰 값을 만들어라.
// 30의 배수가 되는 조건 0으로 나눠 떨어저야 하고 각 자리의 수들의 합이 3의 배수여야 한다.
                     
int main()
{
    string str;
    cin >> str;
    // 내림차순 정렬 
    sort(str.rbegin(), str.rend());
    int sum = 0;
    for(auto &el : str)
        sum += el - 48;
    
    if(str.back() == '0' && sum % 3 == 0)
        cout << str << endl;
    else
        cout << -1 << endl;

    return 0;
}
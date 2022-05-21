#include <iostream>
using namespace std;

int main()
{
    int num;
    int answer = 0;
    cin >> num;
    int tmp = num % 5;
    // 5로 나누어 떨어지면 
    if(!(num % 5))
    {
        answer = num / 5;
        cout << answer;
    }
    // 나눠 떨어지지 않는다면
    else
    {   // 나눠 떨어질 때까지 
        while(1)
        {
            num -= 3;
            answer++;
            if(!(num % 5))
            {
                answer += num / 5;
                num = 0;
                break;
            }
            else if(num <= 0)
                break;
        }
        if(num == 0)
            cout << answer;
        else
            cout << "-1";
    }
    return 0;
}
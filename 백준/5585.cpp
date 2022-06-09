#include <iostream>

using namespace std;
/* 
동전 500, 100, 50, 10, 5, 1
존재할 때 거스름돈을 만들 수 있는
최소한의 동전의 개수를 구하여라.

동전들의 관계를 보았을 때 서로 배수가 되는것을 
확인 할 수 있다. 
이를 통해 큰 동전의 개수부터 구하는 방법을 이용하면
문제를 해결할 수 있을 것이다. 
*/

int main()
{ 
    int num; 
    // 거스름돈 입력 
    cin >> num;
    // 동전의 개수 
    num = 1000 - num;
    int answer = 0;
    int coin[6] = {500, 100, 50, 10, 5, 1};
    for(int i=0 ; i < 6; i++)
    {   
        int tmp = num / coin[i];
        num -= (num / coin[i]) * coin[i];
        if(num != 0)
            answer += tmp; 
        else
        {
            answer += tmp;
            break;
        }     
    }
    cout << answer;
    return 0;
}
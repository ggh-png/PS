#include <iostream>
#include <vector>

using namespace std;


int main()
{
    int num, money, answer=0;
    cin >> num >> money;

    vector<int> coin(num);
    // 동전 입력 
    for(int i=0; i < num; i++)
        cin >> coin[i];
    // 잔액이 양수이고, 최대코인보다 많을 때
    while(money != 0)    
        for(int i = num-1; i >= 0; i--)
            while(money >= coin[i])
            {
                money -= coin[i];
                answer++;
            }    
    cout << answer;

    return 0;
}
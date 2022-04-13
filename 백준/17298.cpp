#include <iostream>
#include <vector>
#include <stack>

using namespace std;
// 오큰수가 의미하는 것 
// NGE[1] ... 배열의 첫번째 인덱스의 오큰수를 의미함 
//            즉, 배열의 첫번째 인덱스 값에 존재하는 요소보다 큰 가장 왼쪽의 요소를 의미함. 
// 정답 백터


int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    int num; 
    cin >> num;
    int OrderList[num];
    int answer[num];
    stack<int> TmpStack;

    for(int i=0; i < num; i++)
        cin >> OrderList[i];

    for(int i=num-1; i >= 0; i--)
    {   // 3 5 2 7
        while (!TmpStack.empty() && TmpStack.top() <= OrderList[i])
            TmpStack.pop();
        if(TmpStack.empty())
            answer[i] = -1;
        else
            answer[i] = TmpStack.top();// -1 7 7 5  
        TmpStack.push(OrderList[i]); // 7 5 3
    }

    for(auto &el : answer)
        cout << el << " ";
    cout << endl;
}
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std; 
// 입력 저장 스택 
// 기본 N까지의 수열스택
// 임시로 담아둘 스택 
// 정답에 입력할 스택  


int main()
{
    int num;
    queue<int> OrderQueue;     // 입력 큐 
    queue<int> NumQueue;       // 기준 큐
    stack<int> TmpStack;        // 임시스택
    vector<string> answer;      // 정답스택
    // 수열 스택 입력 
    cin >> num;
    for(int i=1; i <= num; i++)
    {
        int tmp; 
        cin >> tmp;
        // 4 3 6 8 7 5 2 1
        OrderQueue.push(tmp);
        // 1 2 3 4 5 6 7 8 
        NumQueue.push(i);
    }
    for(int i=0; i < num; i++)
    {   
        while(!OrderQueue.empty())
        {   // 임시스택이 비어있을경우나 스택의 상단과 인풋값이 맞을때 까지 
            if(TmpStack.empty() || TmpStack.top() != OrderQueue.front())
            {   // TmpStack : 1 2 3 4
                TmpStack.push(NumQueue.front());
                // NumQueue : 5 6 7 8
                if(!NumQueue.empty())
                    NumQueue.pop();
                else
                    break;
                answer.push_back("+");  
            }   
            else if(TmpStack.top() == OrderQueue.front())
            {   // TmpStack : 1 2 3 [4].. pop
                TmpStack.pop();
                answer.push_back("-");
                OrderQueue.pop();
                break;
            }       
        } 
    }
    
    if(!TmpStack.empty())
    {
        answer.clear();
        answer.push_back("NO");
    }
    for(auto el : answer)
        cout << el << '\n'; 
}
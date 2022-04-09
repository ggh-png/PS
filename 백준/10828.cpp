#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/* 
선입 선출 
push X: 정수 X를 스택에 넣는 연산이다.
pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 스택에 들어있는 정수의 개수를 출력한다.
empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
*/

// 명령어 저장 


int main()
{
    vector<string> StackList{"push", "pop", "size", "empty", "top"}; 
    vector<int> VectorStack;
    vector<int> answer;
    vector<string> OrderList;

    int num;
    cin >> num;
    for(int i=0; i < num; i++)
    {
        string temp;

        cin >> temp;
        if(temp == "push")
            ++num;
        OrderList.push_back(temp);
    }

    for(int i=0; i < OrderList.size(); i++)
    {
        if(OrderList[i] == "push")
        {
            VectorStack.push_back(stoi(OrderList[i+1]));
        }
        else if(OrderList[i] == "pop")
        {
            if(VectorStack.empty())
                answer.push_back(-1);
            else
            {
                answer.push_back(*(VectorStack.end() - 1));
                VectorStack.pop_back();
            }
        }
        else if(OrderList[i] == "size")
            answer.push_back(VectorStack.size());

        else if(OrderList[i] == "empty")
        {
            if(VectorStack.empty())
                answer.push_back(1);
            else
                answer.push_back(0);
        }

        else if(OrderList[i] == "top")
        {
            if(VectorStack.empty())
                answer.push_back(-1);
            else
            {
                int tmp = *(VectorStack.end() - 1);
                answer.push_back(tmp);
            }
        }
        else
            continue;
    }
    for(auto el : answer)
        cout << el << endl;

    return 0;
}
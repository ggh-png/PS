#include <iostream>
#include <deque>
#include <queue>
#include <string>
using namespace std;

/* 
정수를 저장하는 덱(Deque)를 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.

명령은 총 여덟 가지이다.

push_front X: 정수 X를 덱의 앞에 넣는다.
push_back X: 정수 X를 덱의 뒤에 넣는다.
pop_front: 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
pop_back: 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 덱에 들어있는 정수의 개수를 출력한다.
empty: 덱이 비어있으면 1을, 아니면 0을 출력한다.
front: 덱의 가장 앞에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
back: 덱의 가장 뒤에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
*/

int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int num; 
    cin >> num;
    deque<int> dq;
    queue<int> answer;

    for(int i=0; i < num; i++)
    {
        string temp;
        cin >> temp;
        if(temp == "push_front")
        {
            int tmp;
            cin >> tmp;
            dq.push_front(tmp);
        }
        else if(temp == "push_back")
        {
            int tmp;
            cin >> tmp;
            dq.push_back(tmp);
        }
        else if(temp == "pop_front")
        {
            if(dq.empty())
                answer.push(-1);
            else
            {
                answer.push(dq.front());
                dq.pop_front();
            }    
        }
        else if(temp == "pop_back")
        {
            if(dq.empty())
                answer.push(-1);
            else
            {
                answer.push(dq.back());
                dq.pop_back();
            }    
        }

        else if(temp == "size")
            answer.push(dq.size());
            
        else if(temp == "empty")
            answer.push(dq.empty());
        else if(temp == "front")
        {
            if(dq.empty())
                answer.push(-1);
            else
                answer.push(dq.front());
        }
            
        else if(temp == "back")
        {
            if(dq.empty())
                answer.push(-1);
            else
                answer.push(dq.back());
        }
    }
    // 출력 
    while (!answer.empty())
    {
        cout << answer.front() << '\n';
        answer.pop();
    }
    
    return 0;
}
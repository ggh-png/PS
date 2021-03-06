#include <iostream>
#include <queue>
#include <string>
using namespace std;

/* 
push X: 정수 X를 큐에 넣는 연산이다.
pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 큐에 들어있는 정수의 개수를 출력한다.
empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.

첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 2,000,000)이 주어진다. 
()
둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다. 주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다.
문제에 나와있지 않은 명령이 주어지는 경우는 없다.
*/

int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int num; 
    cin >> num;
    queue<int> q;
    queue<int> answer;

    for(int i=0; i < num; i++)
    {
        string temp;
        cin >> temp;
        if(temp == "push")
        {
            int tmp;
            cin >> tmp;
            q.push(tmp);
        }
        else if(temp == "pop")
        {
            if(q.empty())
                answer.push(-1);
            else
            {
                answer.push(q.front());
                q.pop();
            }    
        }
        else if(temp == "size")
            answer.push(q.size());
        else if(temp == "empty")
            answer.push(q.empty());
        else if(temp == "front")
        {
            if(q.empty())
                answer.push(-1);
            else
                answer.push(q.front());
        }
            
        else if(temp == "back")
        {
            if(q.empty())
                answer.push(-1);
            else
                answer.push(q.back());
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
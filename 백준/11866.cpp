#include <iostream>
#include <queue>
#include <vector>
using namespace std;
/*
work flow
7 3
1 2 3 4 5 6 7 - 
1 2 4 5 6 7 - 3
1 2 4 5 7 - 3 6
1 4 5 7 - 3 6 2
1 4 5 - 3 6 2 7
1 4 - 3 6 2 7 5
4 - 3 6 2 7 5 1
- 3 6 2 7 5 1 4
*/


int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int N, K;
    int idx=0;
    queue<int> q;
    //queue<int> temp;
    queue<int> answer; 
    cin >> N >> K;
    // 1 2 3 4 5 6 7
    for(int i=1; i <= N; i++)
        q.push(i);
    
    while (!q.empty())
    {
        for(int i=1; i < K; i++)
        {   // k번째 자리까지 큐에 담기 
            // 1 2 3 
            int temp = q.front();
            q.pop();
            q.push(temp);     
        }
        answer.push(q.front());
        q.pop();
    }
    cout << "<";
    while (!answer.empty())
    {   
        if(answer.size() == 1)
            cout << answer.front() << ">";
        else
            cout << answer.front() << ", ";
        answer.pop();
    }
}
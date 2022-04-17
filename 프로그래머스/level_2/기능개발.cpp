#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

// 첫 배포시 스택 온 

// 배포가 될때까지 day++
vector<int> solution(vector<int> progresses, vector<int> speeds) 
{
    
    vector<int> day(progresses.size(), 0);
    vector<int> answer;
    stack<int> s;
    int tmp=0;
    for(int i=0; i < progresses.size(); i++)
    {   // 작업이 완료가 될 때 까지
        int days=0;
        while (!progresses[i] >= 100)
        {
            progresses[i] += speeds[i];
            //  첫 배포가  7일이 걸려 
            day[i]++; // 7
        }
    }
    for(int i=progresses.size(); i >= 0; i--)
    {
        // stack 9 4 7
        // tmp 1
        // answer  
        // s 가 비어있지 않고, 이전보다 현재의 작업이 느리면 교체
        tmp++; 
        
        if(!s.empty() && s.top() < day[i])
        {
            answer.push_back(tmp);
            tmp = 0;
        }
        else
            continue;
        s.push(day[i]);
        // s가 비어있지 않고, 이전보다 현재의 작업이 빠르면 삽입 

    }
    // 이전 작업일보다 현재의 작업일이 느리면 지워지고 
    for(auto el : answer)
        cout << el << " ";
    cout << endl;

    return answer;
}


int main()
{
    // 진행상황
    vector<int> progresses = {93, 30, 55};
    // 작어속도 
    vector<int> speeds = {1, 30, 5}; 
    solution(progresses, speeds);
    
    return 0;
}
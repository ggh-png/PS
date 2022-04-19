#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) 
{
    vector<int> day(progresses.size(), 0);
    vector<int> answer;
    stack<int> s;
    
    for(int i=0; i < progresses.size(); i++)
    {   // 작업이 완료가 될 때 까지
        int days=0;
        while (!(progresses[i] >= 100))
        {
            progresses[i] += speeds[i];
            day[i]++;
        }
    }

    int tmp=0;
    int max = day[0];
    for(int i=0; i < day.size(); i++)
    {   // stack이 비어있거나 과거 >= 현재일 경우 
        if(s.empty() || max >= day[i])
        {   // stack에 push
            s.push(day[i]);
            // 마지막일 경우 pop and answer push
            if(i == day.size()-1)
            {
                while (!s.empty())
                {
                    s.pop();
                    tmp++;
                }
                answer.push_back(tmp);
            }
        }  
        // stack이 비어있지 않고, 과거 < 현재일 경우 
        else
        {
            // maxDay init
            max = day[i]; 
            // stack pop
            while (!s.empty())
            {
                s.pop();
                tmp++;
            }
            answer.push_back(tmp);
            // 현재 값 push 
            s.push(day[i]);
            // tmp zero init
            tmp = 0;
            // 마지막일 경우 pop and answer push
            if(i == day.size()-1)
            {
                while (!s.empty())
                {
                    s.pop();
                    tmp++;
                }
                answer.push_back(tmp);
            }
        }
    }
    return answer;
}

int main()
{
    // 진행상황
    vector<int> progresses = {96, 99, 98, 97};
    // 작업속도 
    vector<int> speeds = {1, 1, 1, 1}; 
    solution(progresses, speeds);
    
    return 0;
}



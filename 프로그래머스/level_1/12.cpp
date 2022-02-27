#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX(x,y) ((x>y) ? x : y)

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> sufo_1{1,2,3,4,5}; //5
    vector<int> sufo_2{2,1,2,3,2,4,2,5}; // 8
    vector<int> sufo_3{3,3,1,1,2,2,4,4,5,5}; // 10
    vector<int> sufo_stack(3,0);
    int max=0;


    for(int i=0; i<answers.size(); i++)
    {
        sufo_stack[0] += (sufo_1[i%5] == answers[i]) ? 1 : 0;
        sufo_stack[1] += (sufo_2[i%8] == answers[i]) ? 1 : 0;
        sufo_stack[2] += (sufo_3[i%10] == answers[i]) ? 1 : 0;
    }
    max = (sufo_stack[0] > sufo_stack[1]) ? MAX(sufo_stack[0], sufo_stack[2]) : MAX(sufo_stack[1], sufo_stack[2]);
    
    for(int i=0; i < 3; i++)
    {
        if(max == sufo_stack[i])
            answer.push_back(i+1);
    }       
    sort(answer.begin(), answer.end());
    return answer;
}





int main()
{
    vector<int> answers{1,3,2,4,2};
    solution(answers);
    return 0;
}
#include <iostream>
#include <vector>

using namespace std; 
// 입력 저장 스택 
// 기본 N까지의 수열스택
// 임시로 담아둘 스택 
// 정답에 입력할 스택  


int main()
{
    int num;
    vector<int> OrderStack; // 입력스택 
vector<int> NumQueue;   // 기준스택 
    vector<int> TmpStack;   // 임시스택
    vector<char> answer;    // 정답스택

    cin >> num;
    for(int i=1; i <= num; i++)
    {
        int tmp; 
        cin >> tmp;
        OrderStack.push_back(tmp);
        NumQueue.push_back(i);
    }
    for(int i=0; i < OrderStack.size(); i++)
    {
        for(int j=0; j < OrderStack[i]; j++) // 4 번까지 push 
        {
            TmpStack.push_back(NumQueue[0]); // 1 2 3 4 
            NumQueue.erase(NumQueue.begin()) // 큐 pop ... 5 6 7 8
        }
            
    }
}
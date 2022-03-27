#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
// H index를 구하는법 
// 아마 어떤 요소를 기준으로 요소 이상의 값의 개수가 최댓값이 될 수 있는 기준요소를 구하는거겠지? 

int solution(vector<int> citations) 
{
    int answer = 0;
    int i;
    sort(citations.rbegin(), citations.rend());

    for(i=0; i < citations.size(); i++)
    {   
        if(citations[i] < i+1)
            return answer = i;
        
        else if(citations[i] == i+1)
            return answer = i+1;     
    }
            
    answer = i;    
    return answer;
}

int main()
{
    vector<int> citations{0,0,0,0,0};
    solution(citations);
    return 0;
}
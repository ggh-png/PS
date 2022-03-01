#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// 총 체육복 1개분 배분 
// 여벌 체육복 배분 
// lost 된 체육복 차감
// 수업에 참여 불가능한 인원 조사
// 수업 가능 인원 조사(여분 체육복 지급 전)

// 수업 참여가 불가능한 인원들이 착용 가능한 여분 체육복 조사
// 여분 체육복 배분 
// 수업 가능한 인원 조사


int solution(int n, vector<int> lost, vector<int> reserve) 
{
    int answer = 0;
    int tempLost = 0;
    vector<int> impossibleClass;
    vector<int> possibleSuit;
    vector<int> spareSuit;
    

    // 총 체육복 1개분 배분 
    vector<int> suitSituation(n,1);
    

    sort(reserve.begin(), reserve.end());
    sort(lost.begin(), lost.end());


    // 여벌 체육복 배분 
    for(int i=0; i < reserve.size(); i++)
        suitSituation[reserve[i] - 1] += 1;
    // lost된 체육복 차감 
    for(int i=0; i < lost.size(); i++)
        suitSituation[lost[i] - 1] -= 1;

    // 수업에 참여 불가능한 인원 조사
    for(int i=0; i < suitSituation.size(); i++)
    {
        if(suitSituation[i] == 2) // 빌려줄 수 있을때  
        {
            if(i == 0)
            {
                if(suitSituation[i+1] == 0)
                {
                    suitSituation[i+1] += 1;
                    suitSituation[i] -= 1;
                }  
            }
            else if(i == n-1)
            {
                if(suitSituation[i-1] == 0)
                {
                    suitSituation[i-1] += 1;
                    suitSituation[i] -= 1;
                }
            }
            else 
            {
                if(suitSituation[i-1] == 0)
                {
                    suitSituation[i-1] += 1;
                    suitSituation[i] -= 1;
                }
                else if(suitSituation[i+1] == 0)
                {
                    suitSituation[i+1] += 1;
                    suitSituation[i] -= 1;
                }
            }
        }
    }

    for(auto el : suitSituation)
        answer += (el != 0) ? 1 : 0; 
 
    return answer;
}

int main()
{
    int n = 14;
    vector<int> lost{1, 14};
    vector<int> reserve{3, 14};
    solution(n, lost, reserve);
    return 0;
}
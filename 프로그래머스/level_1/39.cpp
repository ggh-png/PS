#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> nums) 
{
    int answer = 0;
    vector<int> temp;
    for(int i=0; i < nums.size(); i++)
        for(int j=i+1; j < nums.size(); j++)
            for(int k=j+1; k < nums.size(); k++) 
                temp.push_back(nums[i] + nums[j] + nums[k]);
                // 모든 경우의 수 입력
    // 중복된 요소제거 
    for(int i=0; i < temp.size(); i++)
    {
        int temp_num = 0;
        for(int j=2; j < temp[i]; j++) // 소수인지 판별 // 최소 3 
            temp_num += (temp[i] % j) == 0 ? true : false;
        answer += (temp_num == 0) ? true : false;
    }
    // 소수 판별 
    return answer;
}

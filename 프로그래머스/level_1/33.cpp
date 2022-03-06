#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// n번째 문자열을 기준으로 오름차순 정렬 
// n번째 문자 추출 
// 추출된 문자에 번호 부여 

vector<string> solution(vector<string> strings, int n) 
{
    vector<string> answer;
    vector<char> temp; 
    sort(strings.begin(), strings.end());

    for(int i=0; i < strings.size(); i++)   
        temp.push_back(strings[i][n]);
    sort(temp.begin(), temp.end());

    for(int i=0; i < strings.size(); i++)
        for(int j=0; j < temp.size(); j++)
            if(strings[j] != "NULL")
            {
                if(temp[i] == strings[j][n])
                {
                    answer.push_back(strings[j]);
                    strings[j] = "NULL";    
                }
            }
    return answer;
}
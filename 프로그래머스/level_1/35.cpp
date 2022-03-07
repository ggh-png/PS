#include <string>
#include <vector>
#include <iostream>

using namespace std;


// 백터에 저장 
// 홀 짝수 구분 뒤 대문자로 초기화 --32
// 정답 입력 각 단어는 '하나 이상'의 공백문자로 구분되어 있습니다.

string solution(string s) 
{
    vector<string> temp;
    string answer = "";
    string temp_s;
    for(int i=0; i < s.size(); i++)
    {
        temp_s += s[i];
        if(s[i] == ' ' || i == s.size()-1)
        {
            temp.push_back(temp_s);
            temp_s.clear();
        }           
    }
    for(int i=0; i < temp.size(); i++)
    {
        for(int j=0; j < temp[i].size(); j++)
        {
            if(j % 2 != 0)
                if((int)temp[i][j] != 32)
                    if((int)temp[i][j] >= 65 && (int)temp[i][j] <= 90) // 대문자면 
                        temp[i][j] = (char)((int)temp[i][j] + 32);// 소문자로

            if(j % 2 == 0)
                if((int)temp[i][j] != 32)
                    if((int)temp[i][j] >= 97 && (int)temp[i][j] <= 122) // 소문자면 
                        temp[i][j] = (char)((int)temp[i][j] - 32);  // 대문자로
        }
        answer += temp[i];
    }
    

    return answer;
}


#include <string>
#include <vector>
#include <bitset>
#include <iostream>

using namespace std;
// 미로 크기 설정 
// vector_map에 저장 
// arr1, arr2 2진수 출력
// arr + arr2 or 연산 
// # 맵 출력 


vector<string> solution(int n, vector<int> arr1, vector<int> arr2) 
{
    vector<string> answer;
    vector<string> map;

    
    for(int i=0; i < n; i++)
        map.push_back(bitset<16>(arr1[i] | arr2[i]).to_string());

    for(int i=0; i < n; i++)
    {
        string temp = "";
        for(int j=16-n; j < 16; j++)
        {   
            temp += map[i][j] == '0' ? " " : "";
            temp += map[i][j] == '1' ? "#" : "";
            
        }
        answer.push_back(temp);
    }
    return answer;
}

int main()
{
    const int n = 6;
    vector<int> arr1{46, 33, 33 ,22, 31, 50};
    vector<int> arr2{27 ,56, 19, 14, 14, 10};
    solution(n, arr1, arr2);
    return 0; 
}
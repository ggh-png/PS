#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
// 앞자리 기준으로 
// 내림차순 정렬 
// 문자열에 저장 

bool compare(int a, int b)
{ 
    string tmp_1 = to_string(a) + to_string(b);
    string tmp_2 = to_string(b) + to_string(a);
    return  tmp_1 > tmp_2;
}
string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(), numbers.end(), compare);
    for(auto el : numbers)
        answer += to_string(el);
    if(answer[0] == '0')
        answer = "0";
    return answer;
}

int main()
{
    vector<int> numbers = {3, 30, 34, 5, 9};
    solution(numbers);
}
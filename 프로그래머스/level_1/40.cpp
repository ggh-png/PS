#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "김서방은 ";
    string temp;
    for(int i=0; i < seoul.size(); i++)
        answer += seoul[i] == "Kim" ? to_string(i) : "";
    answer += "에 있다";
    return answer;
}
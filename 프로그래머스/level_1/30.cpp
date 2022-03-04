#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;

    if(s.size() != 4 && s.size() != 6)
        return false;
    for(auto el : s)
    {
        if((int)el > 47 && (int)el < 58)
            continue;
        else
            return false;      
    }
    return answer;
}
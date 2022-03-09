#include <string>

using namespace std;

string solution(string s, int n) 
{
    string answer = "";
    int temp_s=0;
    for(auto el : s)
    {
        if(el != ' ')
        {
            if(el >= 'A' && el <= 'Z')
            {
                temp_s = ((int)el + n) > 'Z' ? ((int)el + n) - 26 : ((int)el + n);
                answer += (char)temp_s; 
            }
            else if(el >= 'a' && el <= 'z')
            {
                temp_s = ((int)el + n) > 'z' ? ((int)el + n) - 26 : ((int)el + n);
                answer += (char)temp_s; 
            }
        }
        else
            answer += el;
    }
    return answer;
}
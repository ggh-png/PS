#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int n) {
    
    string su = "수";
    string bak = "박";
    string answer;
    for(int i=0; i < n; i++)
    {
        if(i%2==0)
            answer += su;
        else
            answer += bak; 
    }
    cout << answer << endl;
    return answer;
}

int main()
{
    int n = 3;
    solution(n);
    return 0;
}
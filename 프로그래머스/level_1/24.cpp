#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;
    while (n>=1)
    {
        answer += n%10;
        n /= 10;
    }

    return answer;
}
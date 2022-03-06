#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) 
{
    long long answer = 0;
    int max, min;
    max = a >= b ? a : b;
    min = a <= b ? a : b;
    for(int i=min; i <= max; i++)
        answer += i;
    return answer;
}
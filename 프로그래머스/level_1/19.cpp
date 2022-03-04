#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<long long> solution(int x, int n) 
{
    vector<long long> answer;
    for(int i=1; i <= n; i++)
    {
        answer.push_back(x * i);
    }
    return answer;
}




int main()
{
    int x = 4;
    int n = 5;
    return 0;
}
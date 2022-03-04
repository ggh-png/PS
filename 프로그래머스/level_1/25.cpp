#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long solution(long long n) 
{
    long long answer = 0;
    vector<int> temp;
    while (n > 0)
    {
        temp.push_back(n%10);
        n /= 10;
    }
    sort(temp.begin(), temp.end());
    for(int i=0; i < temp.size(); i++)
        answer += pow(10, i)*temp[i];    
    return answer;

}

int main()
{
    long long n = 118372;
    solution(n);
    return 0; 
}
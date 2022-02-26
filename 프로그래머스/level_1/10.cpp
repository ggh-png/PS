#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    while (n>=1)
    {
        answer.push_back(n%10);
        n /=10; 
    }
    
    for(auto el : answer)
        cout << el << " ";
    cout << endl;
    return answer;
}

int main()
{
    long long n = 12345;
    solution(n);
}
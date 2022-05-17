#include <iostream>
#include <vector>

using namespace std;

long long sum(vector<int> &a)
{
    long long answer = 0;
    for(auto &el : a)
        answer += el;
    return  answer;
}

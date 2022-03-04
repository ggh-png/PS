#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) 
{
    double answer = 0;
    for(auto el : arr)
        answer += el;
    answer /= arr.size();
    return answer;
}

int main()
{
    vector<int> arr{1,2,3,4};
    solution(arr);
    return 0;
}
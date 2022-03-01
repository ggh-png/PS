#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers) 
{
    int answer=0;
    vector<int> num{0,1,2,3,4,5,6,7,8,9};
    //vector<int> num{0,1,2,3,4,5,6,7,8,9};
    
    sort(numbers.begin(), numbers.end());

    for(int i=0; i < 10; i++)
    {
        for(int j=0; j < numbers.size(); j++)
            if(num[i] == numbers[j])
                num[i] = 0;
    }
    for(auto el : num)
        answer += el;
    return answer;

}


int main ()
{
    vector<int> numbers{1,2,3,4,6,7,8,0};
    solution(numbers);
    return 0;
}
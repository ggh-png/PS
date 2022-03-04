#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int index=0;
    int min = arr[0];
    for(int i=0; i < arr.size(); i++)
    {
        if(arr[i] < min)
        {
            min = arr[i];
            index = i;
        }
    }

    for(int i=0; i < arr.size(); i++)
    {
        if(i == index)
            continue;
        answer.push_back(arr[i]);
    }

    if(answer.empty())
    {
        answer.push_back(-1);
    }
    return answer;
}

int main()
{
    vector<int> arr{4,3,2};
    solution(arr);
    return 0;
}
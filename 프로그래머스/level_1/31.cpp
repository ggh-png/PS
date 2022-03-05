#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 가로 세로 길이 비교 길이가 긴 것을 스왑 
// 

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    vector<int> width;
    vector<int> lenght;
    int temp;
    for(int i=0; i < sizes.size(); i++)
    {
        width.push_back(sizes[i][0]);
        lenght.push_back(sizes[i][1]);
        if(width[i] < lenght[i])
        {
            temp = width[i];
            width[i] = lenght[i];
            lenght[i] = temp;
        }
    }
    sort(width.rbegin(), width.rend());
    sort(lenght.rbegin(), lenght.rend());
    answer = width[0] * lenght[0];
    return answer;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

// 산술평균 
// 중앙값
// 최빈값 - 여러개일 경우 두번째로 작은 값 ~ counting sort 
// 최소 최대 범위 

vector<int> solution(vector<int> &count, int num)
{
    vector<int> answer;

    // 산술평균
    double aver=0;
    for(int i=0; i < count.size(); i++)
        aver += count[i] * i;
    answer.push_back(floor((aver / num) + 0.5));
    // 중앙값
    int mid = count.size() / 2;
    for(int i=0; i < count.size(); i++)
    {
        if(mid == 0)
    }
    answer.push_back(arr[mid]); 
    // 최빈값 
    return answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> count(4001, 0);
    int num, temp;
    cin >> num; 
    for(int i=0; i < num; i++)
    {
        cin >> temp;
        count[temp] += 1;
    }    

    
    for(auto el : solution(count, num))
        cout << el << " ";
    cout << endl;

    return 0;
}
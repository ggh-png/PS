#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 오름차순 정리(중복 제거)
// 좌표 압축 인덱스 부여 
// 기존 배열과 비교 후 인덱스 값 입력 
// index : 압축좌표 k : 기존 좌표 begin : 압축좌표의 앞단 end : 압축 좌표의 뒷단
int BinarySearch(vector<int> index,int k ,int begin ,int end)
{
    if(begin > end) return - 1;
    int m = (begin + end) / 2;
    if(index[m] == k) return m;
    else if(index[m] > k) return BinarySearch(index, k, begin, m-1);
    else return BinarySearch(index, k, m+1, end);
}

int main()
{
    int num, temp;
    vector<int> index;
    vector<int> x_list;
    scanf("%d", &num);
    for(int i=0; i < num; i++)
    {
        scanf("%d", &temp);
        index.push_back(temp);
        x_list.push_back(temp);
    }
    sort(index.begin(), index.end());
    // 중복제거 
    index.erase(unique(index.begin(), index.end()), index.end());
    // index 부여
    for(int i=0; i < x_list.size(); i++)
        x_list[i] = BinarySearch(index, x_list[i], 0, index.size());  
    for(auto el : x_list)
        printf("%d ", el);
    printf("\n");            
}
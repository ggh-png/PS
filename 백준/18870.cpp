#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 오름차순 정리(중복 제거)
// 좌표 압축 인덱스 부여 
// 기존 배열과 비교 후 인덱스 값 입력 
// index : 압축좌표 k : 기존 좌표 begin : 압축좌표의 앞단 end : 압축 좌표의 뒷단

int main()
{
    int num, temp;
    vector<int> index;
    vector<int> x_list;
    // 값 입력 
    scanf("%d", &num);
    for(int i=0; i < num; i++)
    {
        scanf("%d", &temp);
        index.push_back(temp);
        x_list.push_back(temp);
    }
    // 오름차순 정렬
    sort(index.begin(), index.end());
    // 중복제거 
    index.erase(unique(index.begin(), index.end()), index.end());
    // index 부여
    for(int i=0; i < x_list.size(); i++)
        printf("%ld ", (lower_bound(index.begin(), index.end(), x_list[i]) - index.begin()));      
}
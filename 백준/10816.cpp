#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int A_num, M_num;
    cin >> A_num;
    int A[A_num];
    for(int i=0; i < A_num; i++)
        cin >> A[i];
    
    // 기준 리스트 오름차순 정렬 
    sort(A, A + A_num);

    cin >> M_num;
    int answer[M_num];
    
    for(int i=0; i < M_num; i++)
    {
        int temp;
        cin >> temp;
        // 이진탐색을 통한 존재유무 탐색 때문에 오름차순 정렬이 필요.   
        int cnt = upper_bound(A, A + A_num, temp) - lower_bound(A, A + A_num, temp);
        answer[i] = cnt;
    }
    for(int i=0; i < M_num; i++)
        cout << answer[i] << " ";

    return 0;
}
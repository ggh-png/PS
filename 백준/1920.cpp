#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

/* 
N개의 정수 A[1], A[2], …, A[N]이 주어져 있을 때,
이 안에 X라는 정수가 존재하는지 알아내는 프로그램을 작성하시오.
단
모든 정수의 범위는 -231 보다 크거나 같고 231보다 작다. 
    int로 받는것이 아닌 string으로 받도록 하자.
*/

int main()
{
    // 존재 기준 리스트
    
    // 확인할 리스트
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int A_num, M_num;
    cin >> A_num;
    vector<string> A(A_num);
    for(int i=0; i < A_num; i++)
        cin >> A[i];
    
    // 기준 리스트 오름차순 정렬 
    sort(A.begin(), A.end());

    cin >> M_num;
    vector<int> answer;
    for(int i=0; i < M_num; i++)
    {
        string temp;
        cin >> temp;
        // 이진탐색을 통한 존재유무 탐색 때문에 오름차순 정렬이 필요.
        int index = lower_bound(A.begin(), A.end(), temp) - A.begin();
        if(temp == A[index])
            answer.push_back(1);
        else
            answer.push_back(0);
    }
    
    for(auto el : answer)
        cout << el << '\n';
    
    return 0;
}
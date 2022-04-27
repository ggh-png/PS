#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

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
    vector<bool> answer;
    for(int i=0; i < M_num; i++)
    {
        string temp;
        cin >> temp;
        // 이진탐색을 통한 존재유무 탐색 때문에 오름차순 정렬이 필요.
        int index = lower_bound(A.begin(), A.end(), temp) - A.begin();
				// 요소가 존재하면
        if(temp == A[index])
            answer.push_back(1);
        else
            answer.push_back(0);
    }
    
    for(auto el : answer)
        cout << el << " ";
    cout << '\n';
    
    return 0;
}
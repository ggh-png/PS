#include <iostream>
#include <vector>

using namespace std;
// 오큰수가 의미하는 것 
// NGE[1] ... 배열의 첫번째 인덱스의 오큰수를 의미함 
//            즉, 배열의 첫번째 인덱스 값에 존재하는 요소보다 큰 가장 왼쪽의 요소를 의미함. 
// 정답 백터
// 큰 요소를 찾아야 함 max index를 찾으면 저장. 

// 백터를 사용하니 push_back에서 속도가 느려진다는것을 확인했다. 
// 따라서 두가지 해결방안이 있는데 일단 백터의 크기를 정해두고 하는 방법과 
// 배열을 사용하는 것이다. 
int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    int num;
    cin >> num;
    int OrderList[num];
    int answer[num];
    for(int i=0; i < num; i++)
        cin >> OrderList[i];

    // 3 5 2 7
    // 5 7 7 -1
    for(int i=0; i < num; i++)
    {
        int NGE = OrderList[i]; // 오큰수 기준값 지정 
        for(int j=i+1; j < num; j++)
        {
            if(NGE < OrderList[j])
            {
                NGE = OrderList[j];
                answer[i] = OrderList[j];
                break;
            }
            if(NGE != OrderList[i])
                break;
        }
        // 오큰수가 없으면 
        if(NGE == OrderList[i])
            answer[i] = -1;
    }
    for(auto el : answer)
        cout << el << " ";
    cout << '\n';
}
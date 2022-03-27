#include<iostream>
using namespace std; 


// 데이터의 개수 입력 후 데이터 입력 하기  
// 카운팅할 배열 선언 
// 카운팅 하기 
// 카운팅 한 배열 출력 

int main()
{   
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    // counting arr 
    int arr[10001]={0}; 
    int num;
    int tmp;

    // 데이터 입력 
    cin >> num;
    for(int i=1; i <= num; i++)
    {
        cin >> tmp;
        arr[tmp]++;
    }
    // 결과 출력
    for(int i=1; i < 10001; i++)
        while(arr[i] != 0)
        {
            cout << i << '\n';
            arr[i]--; 
        }       
    return 0;
}
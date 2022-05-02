#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

/*
case 1
A 1 1 1 6 0
B 2 7 8 3 1
  1 1 0 1 6
  2 7 0 3 6 = 18 
SOL
A의 내림차순 정리 
B의 오름차순 정리
곱 
*/

int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    vector<int> A;
    vector<int> B;
    int num;
    
    cin >> num;
    for(int i=0; i < num; i++)
    {
        int temp; 
        cin >> temp; 
        A.push_back(temp);
    }
    for(int i=0; i < num; i++)
    {
        int temp; 
        cin >> temp; 
        B.push_back(temp);
    }
    sort(A.rbegin(), A.rend());
    sort(B.begin(), B.end());
    
    int result = 0;
    for(int i=0; i < num; i++)
        result += A[i] * B[i];

    cout << result;
    return 0;

}
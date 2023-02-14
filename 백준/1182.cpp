#include <iostream>

using namespace std;

int n, m;
int cnt = 0;

int arr[22];

void sol(int sum, int idx)
{
    if(idx == n)
        return;
    // 만약 합의 값과 일치하면 
    if(sum + arr[idx] == m)
        cnt++;
    // 배열을 검사하고 적용하지 않았을 경우 
    sol(sum, idx+1);
    sol(sum + arr[idx], idx+1);
}

int main()
{
    cin >> n >> m;
    for(int i=0; i < n; i++)
        cin >> arr[i];
    
    sol(0, 0);
    cout << cnt << endl;
    return 0;
}
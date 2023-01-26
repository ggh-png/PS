#include <iostream>
#include <vector>

using namespace std;

int sizee;
int ans = 987;
int arr[] = {64,32,16,8,4,2,1};
bool visited[7];

// 사이즈는 최대한 근접하게 

void sol(int idx, int cnt, int sum, int ss)
{
    if(sum == sizee && sum > ss)
    {
        ans = min(ans, cnt);
        ss = sum;
    }
    for(int i=idx; i < 7; i++)
        if(arr[i] + sum <= sizee)
        {  
            visited[i] = 1;
            sol(i, cnt+1, sum+arr[i], ss);
            visited[i] = 0;
        }
    
    return;
}

int main()
{
    cin >> sizee;
    sol(0, 0, 0, 0);
    cout << ans << endl;
}
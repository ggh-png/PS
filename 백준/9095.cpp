#include <iostream>
using namespace std;


// 정수 n이 주어졌을 때, n을 1, 2, 3의 합으로 나타내는 방법의 수를 구하는 프로그램을 작성하시오.
int n;
int ans;
int num;
void sol(int num, int sum)
{
    if(sum == num)
    {
        ans++;
        return;
    }
    if(sum > num)
        return;
    for(int i=1; i < 4; i++)
        sol(num, sum + i);
}


int main()
{
    cin >> n;
    for(int i=0; i < n; i++)
    {
        cin >> num;
        ans = 0;
        sol(num, 0);
        cout << ans << endl;
    }
    return 0;
}
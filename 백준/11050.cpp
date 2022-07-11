#include <iostream>

using namespace std;

int factorial(int a)
{
    int ans = 1;
    for(int i=a; i > 0; i--)
        ans *= i;
    return ans;
}



int main()
{
    int n, k;
    cin >> n >> k;
    int answer = factorial(n) / (factorial(k) * factorial(n-k));
    cout << answer << endl;
    return 0;
}